#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "loginwindow.h"
#include "restaurateurpage.h"
#include "ui_loginwindow.h"
#include "iutfood_firstpage.h"
#include "adminpage.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);
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
            int status = query.value("status").toInt();
            if(status == 0){
                QMessageBox::information(this, "موفق", "ورود موفقیت‌آمیز بود!");
            }
            if(status == 1){
                QMessageBox::information(this, "موفق", "ورود ادمین موفقیت‌آمیز بود!");
                Adminpage *adminWin = new Adminpage();
                adminWin->setAttribute(Qt::WA_DeleteOnClose);
                adminWin->show();
                this->close();
            }
            if(status == 2){
                QMessageBox::information(this, "موفق", "ورود  رستوراندار موفقیت‌آمیز بود!");
                Restaurateurpage *rstrwin = new Restaurateurpage();
                rstrwin->setAttribute(Qt::WA_DeleteOnClose);
                rstrwin->show();
                this->close();
            }
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
