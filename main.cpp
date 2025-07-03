#include "iutfood_firstpage.h"
#include "qsqlerror.h"


#include <QApplication>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QString>




void createOrdersDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("orders.db");

    if (!db.open()) {
        qDebug() << "❌ خطا در باز کردن دیتابیس سفارشات!";
        return;
    }

    QSqlQuery query;

    // 🔹 ساخت جدول سفارشات
    bool success = query.exec(R"(
        CREATE TABLE IF NOT EXISTS orders (
            order_id INTEGER PRIMARY KEY,
            customer_username TEXT NOT NULL,
            restaurant_username TEXT NOT NULL,
            title TEXT NOT NULL,
            total_price REAL NOT NULL
        )
    )");

    if (!success) {
        qDebug() << "❌ خطا در ساخت جدول:" << query.lastError().text();
        db.close();
        return;
    }

    // 🔸 درج سفارش‌های نمونه
    query.prepare(R"(
        INSERT OR IGNORE INTO orders (order_id, customer_username, restaurant_username, title, total_price)
        VALUES (?, ?, ?, ?, ?)
    )");

    QList<QVariantList> sampleOrders = {
        {1001, "ali123", "burgerhouse", "همبرگر مخصوص + نوشابه", 145000},
        {1002, "sara_99", "pizza_hot", "پیتزا چیکن باربیکیو", 220000},
        {1003, "mohsen12", "shila_kabab", "چلوکباب سلطانی", 185000},
        {1004, "niloofar", "homemade_foods", "قرمه سبزی + سالاد شیرازی", 98000},
        {1005, "ehsanX", "fastfoodcity", "هات داگ ویژه + سیب‌زمینی", 125000}
    };

    for (const auto& order : sampleOrders) {
        query.addBindValue(order[0]);
        query.addBindValue(order[1]);
        query.addBindValue(order[2]);
        query.addBindValue(order[3]);
        query.addBindValue(order[4]);

        if (!query.exec()) {
            qDebug() << "❌ خطا در ثبت سفارش نمونه:" << query.lastError().text();
        }
    }

    qDebug() << "✅ جدول سفارشات و سفارش‌های نمونه با موفقیت ایجاد شد.";
    db.close();
}
void createrestaurantsTable() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("restaurant.db");

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
            status INTEGER,
            type TEXT,
            username TEXT
        )
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO restaurant (ID ,name, address, rate,status,type,username)
        VALUES (1,'Shila Burger', 'Esfahan, Towhid Sq.', 3.9,0,"فست فود","rest12")
    )");

    query.exec(R"(
        INSERT OR IGNORE INTO restaurant (ID ,name, address, rate,status,type,username)
        VALUES (2,'Pizza Hot', 'Shiraz, Zand Blvd.', 4.5,1,"فست فود","azadeh")
    )");

    db.close();
}
void createcommenttable() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("comments.db");

    if (!db.open()) {
        qDebug() << "خطا در باز کردن دیتابیس comments.db!";
        return;
    }

    QSqlQuery query;

    query.exec(R"(
    CREATE TABLE IF NOT EXISTS comments (
        restaurantusername TEXT NOT NULL,
        username TEXT NOT NULL,
        comment TEXT NOT NULL,
        likes INTEGER NOT NULL,
        rating REAL DEFAULT 3
    )
)");

    query.exec(R"(
    INSERT OR IGNORE INTO foods (restaurantusername, username, comment, likes , rating)
    VALUES ("zxrest", 'amirr', 'بسیار عالی و خوشمزه', '10', 4)
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

    query.exec(R"(
    CREATE TABLE IF NOT EXISTS foods (
        foodcode INTEGER PRIMARY KEY,
        foodname TEXT NOT NULL,
        foodtype TEXT NOT NULL,
        restaurantname TEXT NOT NULL,
        price INTEGER NOT NULL,
        rating REAL DEFAULT 3,
        restaurantusername TEXT NOT NULL
    )
)");

    query.exec(R"(
    INSERT OR IGNORE INTO foods (foodcode, foodname, foodtype, restaurantname , price, rating, restaurantusername)
    VALUES (1234, 'hot dog', 'fastfood', 'ZX', 150000, 4.5, 'zxrst')
)");


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
    query.exec(R"(
        INSERT OR IGNORE INTO users (name, username, password, email , status)
        VALUES ('رستوران اصفهان', 'rest1244', '5678', 'amir@example.com' , '5')
    )");


    db.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createUserTable();
    createrestaurantsTable();
    createFoodsTableAndInsertData();
    createOrdersDatabase();
    createcommenttable();
    QString exeDir = QCoreApplication::applicationDirPath();
    qDebug() << "Executable directory:" << exeDir;
    QString currentPath = QDir::currentPath();
    qDebug() << "Current working directory:" << currentPath;
    IUTFood w;
    w.show();
    return a.exec();
}
