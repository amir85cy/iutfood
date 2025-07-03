#include "managemenu.h"
#include "ui_managemenu.h"
#include "restaurateurpage.h"
#include "global.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

void managemenu::deleteSelectedRow()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "هشدار", "ابتدا یک ردیف را انتخاب کنید.");
        return;
    }

    QString foodName = ui->tableWidget->item(row, 2)->text();  // ستون نام غذا (اینجا ستون 2 است)
    QString username = loggedInUsername;

    // اتصال به دیتابیس غذا
    QSqlDatabase foodDb = QSqlDatabase::database("food_connection");
    if (!foodDb.isOpen()) {
        if (!foodDb.open()) {
            QMessageBox::critical(this, "خطا", "اتصال به پایگاه داده غذا ممکن نیست!");
            return;
        }
    }

    QSqlQuery query(foodDb);
    query.prepare("DELETE FROM Foods WHERE foodName = :foodName AND restaurantUsername = :username");
    query.bindValue(":foodName", foodName);
    query.bindValue(":username", username);

    if (query.exec()) {
        ui->tableWidget->removeRow(row);
        QMessageBox::information(this, "موفق", "غذا با موفقیت حذف شد.");
    } else {
        QMessageBox::critical(this, "خطا", "حذف غذا از پایگاه داده شکست خورد.");
        qDebug() << query.lastError().text();
    }
}

managemenu::managemenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::managemenu)
{
    ui->setupUi(this);

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        Restaurateurpage *rstswin = new Restaurateurpage();
        rstswin->setAttribute(Qt::WA_DeleteOnClose);
        rstswin->show();
        this->close();
    });

    qDebug() << "Logged in user $$:" << loggedInUsername;

    // اتصال به دیتابیس user.db برای گرفتن نام رستوران
    QSqlDatabase userDb = QSqlDatabase::addDatabase("QSQLITE", "user_connection");
    userDb.setDatabaseName("restaurant.db");

    QString restaurantName;
    if (userDb.open()) {
        QSqlQuery query(userDb);
        query.prepare("SELECT name FROM restaurant WHERE username = :username");
        query.bindValue(":username", loggedInUsername);
        if (query.exec() && query.next()) {
            restaurantName = query.value(0).toString();
        } else {
            QMessageBox::warning(this, "خطا", "نام رستوران یافت نشد!");
        }
        userDb.close();
    } else {
        QMessageBox::warning(this, "خطا", "اتصال به دیتابیس کاربران برقرار نشد!");
    }

    // اتصال به دیتابیس foods.db
    QSqlDatabase foodDb = QSqlDatabase::addDatabase("QSQLITE", "food_connection");
    foodDb.setDatabaseName("foods.db");

    if (!foodDb.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه داده غذا ممکن نیست!");
        return;
    }

    // تنظیم جدول
    ui->tableWidget->setStyleSheet(R"(
    QHeaderView::section {
        background-color: #f77599;
        border-bottom: 1px solid #aaaaaa;
        padding: 6px;
        font-weight: bold;
        color:black;
        font-family:iranyekan;
    }
    QTableWidget {
        gridline-color: #aaaaaa;
        border: 1px solid #aaaaaa;
        font-family:iranyekan;
    }
    QTableWidget::item:selected {
        background-color: #0066cc;
        color: white;
    }

    )");
    ui->tableWidget->setColumnCount(3);
    QStringList headers = {"قیمت", "دسته‌بندی", "نام غذا"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // دریافت غذاهای مربوط به این رستوران
    QSqlQuery foodQuery(foodDb);
    foodQuery.prepare("SELECT foodname, foodtype, price FROM foods WHERE restaurantusername = :username");
    foodQuery.bindValue(":username", loggedInUsername);
    qDebug()<<loggedInUsername;

    if (foodQuery.exec()) {
        while (foodQuery.next()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(foodQuery.value(0).toString())); // نام غذا
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(foodQuery.value(1).toString())); // دسته بندی
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(foodQuery.value(2).toString())); // قیمت
        }
    } else {
        QMessageBox::warning(this, "خطا", "خواندن غذاها با مشکل مواجه شد!");
    }

    // دکمه افزودن غذا
    connect(ui->addbtn, &QPushButton::clicked, this, [=]() {
        QString name = ui->nameEdit->text().trimmed();
        QString type = ui->typeEdit->currentText().trimmed();
        QString priceStr = ui->priceEdit->text().trimmed();

        if (name.isEmpty() || type.isEmpty() || priceStr.isEmpty()) {
            QMessageBox::warning(this, "هشدار", "همه فیلدها را پر کنید.");
            return;
        }

        bool ok;
        int price = priceStr.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "هشدار", "قیمت باید عدد صحیح باشد.");
            return;
        }

        QString foodCode = QString::number(1000 + (rand() % 9000)); // کد ۴ رقمی تصادفی

        QSqlQuery insertQuery(foodDb);
        insertQuery.prepare(R"(
            INSERT INTO foods (foodcode, foodname, foodtype, restaurantname, restaurantusername, price, rating)
            VALUES (:code, :name, :type, :rname, :ruser, :price, :rating)
        )");
        insertQuery.bindValue(":code", foodCode);
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":type", type);
        insertQuery.bindValue(":rname", restaurantName);
        insertQuery.bindValue(":ruser", loggedInUsername);
        insertQuery.bindValue(":price", price);
        insertQuery.bindValue(":rating", 3);

        if (insertQuery.exec()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(name));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(type));
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(price)));

            ui->nameEdit->clear();
            ui->priceEdit->clear();
            ui->typeEdit->setCurrentIndex(0);
        } else {
            QMessageBox::critical(this, "خطا", "افزودن غذا به پایگاه داده شکست خورد.");
            qDebug() << insertQuery.lastError().text();
        }
    });
    connect(ui->deletebtn, &QPushButton::clicked, this, &managemenu::deleteSelectedRow);

}

managemenu::~managemenu()
{
    QSqlDatabase::removeDatabase("user_connection");
    QSqlDatabase::removeDatabase("food_connection");
    delete ui;
}
