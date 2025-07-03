#include "cart.h"
#include "peygiri.h"
#include "shoppage.h"
#include "ui_cart.h"
#include "global.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QDebug>

#include <QRandomGenerator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QItemSelectionModel>

cart::cart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cart)
{
    ui->setupUi(this);
    socket = globalSocket = new QTcpSocket(nullptr);
    globalSocket = socket;
    //socket->connectToHost("127.0.0.1", 12345);
    // تنظیم انتخاب سطر کامل
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    // رنگ انتخاب‌شده
    ui->tableWidget->setStyleSheet(
        "QTableWidget::item:selected {"
        "background-color: lightcoral;"
        "color: black;"
        "}"
        );

    // تنظیم ستون‌ها
    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"نام غذا", "نام رستوران", "تعداد", "قیمت"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // بارگذاری اطلاعات
    loadCartItems("cart.txt");

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });

    // دکمه حذف از سبد خرید
    connect(ui->deletebtn, &QPushButton::clicked, this, [=]() {
        int row = ui->tableWidget->currentRow();
        if (row < 0) {
            QMessageBox::warning(this, "خطا", "لطفا یک سطر را انتخاب کنید.");
            return;
        }

        auto reply = QMessageBox::question(this, "تایید حذف", "آیا از حذف این مورد مطمئن هستید؟",
                                           QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            ui->tableWidget->removeRow(row);
            updateTotalPrice();
            updateCartFile("cart.txt");
        }
    });
    connect(ui->confirmbtn, &QPushButton::clicked, this, [=]() {
        if (ui->tableWidget->rowCount() == 0) {
            QMessageBox::warning(this, "خطا", "سبد خرید شما خالی است.");
            return;
        }

        auto reply = QMessageBox::question(this, "تایید سفارش", "آیا از ثبت سفارش خود مطمئن هستید؟",
                                           QMessageBox::Yes | QMessageBox::No);
        if (reply != QMessageBox::Yes)
            return;

        // برای هر سطر یک سفارش جدا ارسال می‌کنیم
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
            QString foodName   = ui->tableWidget->item(row, 0)->text();
            QString restName   = ui->tableWidget->item(row, 1)->text();
            QString countStr   = ui->tableWidget->item(row, 2)->text();
            QString priceStr   = ui->tableWidget->item(row, 3)->text();

            int count = countStr.toInt();
            int price = priceStr.toInt();
            int total = count * price;
            qDebug()<<ui->tableWidget->item(row, 1)->text();
            QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "RestInfoConnection");
            db.setDatabaseName("restaurant.db");

            if (!db.open()) {
                qDebug() << "Database Error:" << db.lastError().text();
                QMessageBox::critical(this, "خطا", "اتصال به دیتابیس برقرار نشد.");
                return;
            }

            QSqlQuery query(db);
            query.prepare("SELECT username FROM restaurant WHERE  name = :name");
            query.bindValue(":name", restName);
            if (!query.exec()) {
                qDebug() << "Query Error:" << query.lastError().text();
                QMessageBox::critical(this, "خطا", "خواندن اطلاعات رستوران با مشکل مواجه شد.");
                return;
            }
            QString destrestusername;
            if (query.next()) {
                destrestusername = query.value("username").toString();
            } else {
                QMessageBox::warning(this, "یافت نشد", "رستورانی با این ID پیدا نشد.");
            }

            db.close();
            // مقدار تستی یا از دیتابیس: نام کاربر و نام کاربری رستوران
            QString clientUsername = loggedInUsername;
            QString restUsername = destrestusername;

            // اتصال به سرور (در صورت نیاز)
            if (socket->state() != QAbstractSocket::ConnectedState) {
                socket->connectToHost("127.0.0.1", 12345);
                if (!socket->waitForConnected(1000)) {
                    QMessageBox::warning(this, "خطا", "اتصال به سرور برقرار نشد.");
                    return;
                }
            }

            // ارسال پیام به سرور
            int num = QRandomGenerator::global()->bounded(1000, 10000);
            QString message = QString("%1:%2:%3:%4:%5")
                                  .arg(clientUsername, restUsername, foodName, QString::number(count),QString::number(num));
            socket->write(message.toUtf8());
            socket->flush();
        }

        QMessageBox::information(this, "ثبت شد", "سفارش‌ها با موفقیت ارسال شدند.");
        peygiri *peygiriwin = new peygiri();
        peygiriwin->setAttribute(Qt::WA_DeleteOnClose);
        peygiriwin->show();
        qDebug() << "[Client] Moving socket to peygiri window";
        globalSocket->moveToThread(peygiriwin->thread());
        this->close();
    });

}

cart::~cart()
{
    delete ui;
}

void cart::loadCartItems(const QString &filename)
{
    QFile file(filename);

    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "پیتزا,IUT Pizza,2,150000\n";
            out << "برگر,Burger House,1,85000\n";
            file.close();
        } else {
            QMessageBox::warning(this, "خطا", "امکان ساخت فایل cart.txt وجود ندارد.");
            return;
        }
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "خطا", "امکان باز کردن فایل سبد خرید وجود ندارد.");
        return;
    }

    QTextStream in(&file);
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(',');
        if (parts.size() != 4) continue;

        ui->tableWidget->insertRow(row);
        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(parts[col]);
            item->setTextAlignment(Qt::AlignCenter);

            if (col == 2) {
                // فقط ستون تعداد (قابل ویرایش)
                item->setFlags(item->flags() | Qt::ItemIsEditable);
            } else {
                // بقیه ستون‌ها فقط قابل مشاهده
                item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            }

            ui->tableWidget->setItem(row, col, item);
        }

        row++;
    }

    file.close();
    updateTotalPrice();
}

void cart::updateTotalPrice()
{
    int total = 0;
    int rowCount = ui->tableWidget->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QString countStr = ui->tableWidget->item(row, 2)->text();
        QString priceStr = ui->tableWidget->item(row, 3)->text();

        bool ok1 = false, ok2 = false;
        int count = countStr.toInt(&ok1);
        int price = priceStr.toInt(&ok2);

        if (ok1 && ok2) {
            total += count * price;
        }
    }

    ui->sum->setText(QString::number(total));
}

void cart::removeSelectedItem()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "توجه", "لطفاً یک ردیف را برای حذف انتخاب کنید.");
        return;
    }

    ui->tableWidget->removeRow(row);
    updateCartFile("cart.txt");
    updateTotalPrice();
}


void cart::updateCartFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "خطا", "امکان بروزرسانی فایل سبد خرید وجود ندارد.");
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->tableWidget->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        QStringList parts;
        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            parts << (item ? item->text() : "");
        }
        out << parts.join(',') << "\n";
    }

    file.close();
}
