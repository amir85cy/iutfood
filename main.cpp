#include "iutfood_firstpage.h"

#include <QApplication>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

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
        VALUES ('امیررضا', 'amir', '5678', 'amir@example.com' , '2')
    )");

    db.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createUserTable();
    IUTFood w;
    w.show();
    return a.exec();
}
