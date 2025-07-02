#include "iutfood_firstpage.h"
#include "qsqlerror.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
void createrestaurantsTable() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("restaurant2.db");

    if (!db.open()) {
        qDebug() << "خطا در باز کردن دیتابیس!";
        return;
    }

    QSqlQuery query;

    query.exec(R"(
        CREATE TABLE IF NOT EXISTS restaurant (
            ID INTEGER PRIMARY KEY,
            name TEXT,
            address TEXT,
            rate REAL,
            status INTEGER
        )
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO restaurant (ID ,name, address, rate,status)
        VALUES (1,'Shila Burger', 'Esfahan, Towhid Sq.', 3.9,0)
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO restaurant (ID ,name, address, rate,status)
        VALUES (2,'Pizza Hot', 'Shiraz, Zand Blvd.', 4.5,1)
    )");

    db.close();
}
void createFoodsTableAndInsertData() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("foods.db");

    if (!db.open()) {
        qDebug() << "خطا در باز کردن دیتابیس foods.db!";
        return;
    }

    QSqlQuery query;

    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS foods ("
        "foodcode INTEGER PRIMARY KEY, "
        "foodname TEXT NOT NULL, "
        "foodtype TEXT NOT NULL, "
        "restaurantname TEXT NOT NULL, "
        "price INTEGER NOT NULL, "
        "rating INTEGER DEFAULT 3, "
        "restaurantusername TEXT NOT NULL)"
        );

    if (!success) {
        qDebug() << "خطا در ساخت جدول foods:" << query.lastError().text();
        return;
    }

    // داده‌های نمونه بیشتر
    query.exec("INSERT OR IGNORE INTO foods VALUES (1001, 'قرمه سبزی', 'خورشت', 'رستوران اصفهان', 35000, 4, 'rest12')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1002, 'چلو کباب', 'غذای سنتی', 'رستوران تهران', 45000, 5, 'rest2')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1003, 'پیتزا مخلوط', 'فست فود', 'رستوران اصفهان', 40000, 3, 'rest1')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1004, 'باقالا پلو', 'غذای سنتی', 'رستوران تهران', 30000, 4, 'rest2')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1005, 'برگر', 'فست فود', 'رستوران اصفهان', 38000, 5, 'rest12')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1006, 'سالاد سزار', 'سالاد', 'رستوران تهران', 25000, 3, 'rest2')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1007, 'ماهی کبابی', 'غذای دریایی', 'رستوران اصفهان', 55000, 4, 'rest1')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1008, 'نوشابه', 'نوشیدنی', 'رستوران تهران', 8000, 3, 'rest12')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1009, 'سوپ جو', 'پیش غذا', 'رستوران اصفهان', 15000, 4, 'rest1')");
    query.exec("INSERT OR IGNORE INTO foods VALUES (1010, 'زرشک پلو', 'غذای سنتی', 'رستوران تهران', 32000, 5, 'rest2')");

    qDebug() << "جدول foods ساخته شد و داده‌های نمونه وارد شد.";
    db.close();
}

void createUserTable() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        qDebug() << "خطا در باز کردن دیتابیس!";
        return;
    }

    QSqlQuery query;

    query.exec(R"(
        CREATE TABLE IF NOT EXISTS users (
            name TEXT,
            username TEXT PRIMARY KEY,
            password TEXT,
            email TEXT,
            status INT
        )
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO users (name, username, password, email , status)
        VALUES ('ادمین اصلی', 'admin', '1234', 'admin@example.com' , '1')
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO users (name, username, password, email , status)
        VALUES ('امیررضا', 'amirr', '5678', 'amir@example.com' , '2')
    )");
    query.exec(R"(
        INSERT OR IGNORE INTO users (name, username, password, email , status)
        VALUES ('رستوران اصفهان', 'rest12', '5678', 'amir@example.com' , '2')
    )");


    db.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createUserTable();
    createrestaurantsTable();
    createFoodsTableAndInsertData();
    IUTFood w;
    w.show();
    return a.exec();
}
