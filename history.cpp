#include "history.h"
#include "ui_history.h"
#include "shoppage.h"
#include "global.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidgetItem>
#include <QHeaderView>

history::history(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::history)
{
    ui->setupUi(this);

    // دکمه بازگشت
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });

    // تنظیمات جدول
    ui->tableWidget->setColumnCount(3);
    QStringList headers = { "عنوان سفارش", "رستوران", "قیمت (تومان)" };
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(0);

    // اتصال به دیتابیس سفارشات
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "orders_connection");
    db.setDatabaseName("orders.db");

    if (!db.open()) {
        qDebug() << "❌ خطا در باز کردن دیتابیس orders:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT title, restaurant_username, total_price FROM orders WHERE customer_username = ?");
    query.addBindValue(loggedInUsername);

    if (!query.exec()) {
        qDebug() << "❌ خطا در اجرای کوئری:" << query.lastError().text();
        db.close();
        return;
    }

    // پر کردن جدول
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(query.value(2).toDouble())));
        row++;
    }

    db.close();
}

history::~history()
{
    delete ui;
}
