#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "iutfood_firstpage.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });
    ui->password->setEchoMode(QLineEdit::Password);

    connect(ui->submit, &QPushButton::clicked, this, [=]() {
        QString inputUsername = ui->username->text();
        QString inputPassword = ui->password->text();

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");

        if (!db.open()) {
            QMessageBox::critical(this, "خطا", "اتصال به پایگاه‌داده ناموفق بود.");
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
        query.bindValue(":username", inputUsername);
        query.bindValue(":password", inputPassword);

        if (query.exec() && query.next()) {
            QMessageBox::information(this, "موفق", "ورود موفقیت‌آمیز بود!");
        } else {
            errormsg("نام کاربری یا رمز عبور اشتباه است !");
        }

        db.close();
    });
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
