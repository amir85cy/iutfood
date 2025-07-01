#include "restaurant.h"
#include "adminpage.h"
#include "ui_restaurant.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QDebug>


void restaurant::changestatus(int newstst) {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "اخطار", "هیچ آیتمی انتخاب نشده!");
        return;
    }

    // جدا کردن ID از متن آیتم
    QString line = selectedItem->text();
    int dashIndex = line.lastIndexOf('-');
    int id;
    if (dashIndex != -1) {
        QString numberStr = line.mid(dashIndex + 1).trimmed();
        id = numberStr.toInt();
    } else {
        qDebug() << "فرمت آیتم اشتباه است";
        return;
    }

    // باز کردن دیتابیس صحیح
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("restaurant2.db");

    if (!db.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه‌داده ناموفق بود.");
        return;
    }

    // بررسی وجود رستوران با این ID
    QSqlQuery query;
    query.prepare("SELECT status, name, rate FROM restaurant WHERE ID = :ID");
    query.bindValue(":ID", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "خطا", "اجرای کوئری با خطا مواجه شد:\n" + query.lastError().text());
        db.close();
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "خطا", "رستوران با این شناسه پیدا نشد.");
        db.close();
        return;
    }

    int oldStatus = query.value(0).toInt();
    QString name = query.value(1).toString();
    QString rateStr = query.value(2).toString();

    // بروزرسانی وضعیت رستوران
    query.prepare("UPDATE restaurant SET status = :newStatus WHERE ID = :ID");
    query.bindValue(":newStatus", newstst);
    query.bindValue(":ID", id);

    if (!query.exec()) {
        QString errorText = (newstst == 1) ? "فعال کردن" : "غیرفعال کردن";
        QMessageBox::critical(this, "خطا", errorText + " رستوران ناموفق بود:\n" + query.lastError().text());
    } else {
        QString message = (newstst == 1) ? "رستوران با موفقیت فعال شد!" : "رستوران با موفقیت غیرفعال شد!";
        QMessageBox::information(this, "موفق", message);

        // بروزرسانی متن آیتم در لیست
        QString statusLabel = (newstst == 1) ? "("+rateStr+")" : "🚫(غیرفعال)";
        QString newItemText = statusLabel  + name + "  - " + QString::number(id);
        selectedItem->setText(newItemText);
    }

    db.close();
}

void restaurant::loadRestaurantsFromDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("restaurant2.db");
    qDebug() << "DB Path: " << QDir::currentPath() + "/" + db.databaseName();

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    ui->listWidget->clear();  // پاک کردن آیتم‌های قبلی

    QIcon icon(":/new/images/plate.png");
    QSqlQuery query("SELECT name, rate, ID, status FROM restaurant");

    while (query.next()) {
        QString name = query.value(0).toString();
        QString rate = query.value(1).toString();
        QString id = query.value(2).toString();
        int status = query.value(3).toInt();

        QString displayText;
        if (status == 0) {
            rate = "غیرفعال";
        }
        displayText = '(' + rate + ')' + name + "  - " + id;
        if (status == 0) {
            displayText = "🚫 " + displayText;
        }
        QListWidgetItem* item = new QListWidgetItem(icon, displayText);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

        ui->listWidget->addItem(item);
    }

    db.close();
}

restaurant::restaurant(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::restaurant)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet(R"(
        QListWidget {
            border: 2px solid #aaaaaa;
            border-radius: 12px;
            border-image: url(:/new/images/listbg.jpg);
            font-family:iranyekan;
            padding: 30px;
        }

        QListWidget::item {
            background-color: #90ceb5;
            margin: 4px;
            padding: 8px;
            border-radius: 8px;
            color: #333;
        }

        QListWidget::item:selected {
            background-color: #3399ff;
            color: white;
        }

        QListWidget::item:hover {
            background-color: #3399ff;
            color: black;
        }
        )");
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        Adminpage *adminWin = new Adminpage();
        adminWin->setAttribute(Qt::WA_DeleteOnClose);
        adminWin->show();
        this->close();
    });
    loadRestaurantsFromDatabase();
    connect(ui->onactivebtn, &QPushButton::clicked, this, [=]() { changestatus(0); });
    connect(ui->activebtn, &QPushButton::clicked, this, [=]() { changestatus(1); });
}

restaurant::~restaurant()
{
    delete ui;
}
