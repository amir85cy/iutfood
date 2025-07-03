#include "loginwindow.h"
#include "panel.h"
#include "shoppage.h"
#include "ui_loginwindow.h"
#include "restaurateurpage.h"
#include "adminpage.h"
#include "iutfood_firstpage.h"
#include "global.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

void LoginWindow::errormsg(const QString &matn) {
    QMessageBox msg;

    msg.setText(matn);
    msg.setIcon(QMessageBox::Warning);


    msg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    QFont font("iranyekan", 12, QFont::Bold);
    msg.setFont(font);
    msg.setStyleSheet("QLabel { color: red; padding: 10px; }");

    QPushButton *okBtn = msg.addButton("فهمیدم", QMessageBox::AcceptRole);
    okBtn->setStyleSheet("padding: 3px 6px; font-family: iranyekan; font-size: 10px;");
    msg.exec();
}
LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);

    ui->password->setEchoMode(QLineEdit::Password);

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });

    connect(ui->submit, &QPushButton::clicked, this, [=]() {
        QString inputUsername = ui->username->text().trimmed();
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
            if (status == 0) {
                QMessageBox::information(this, "موفق", "ورود موفقیت‌آمیز بود!");
                ShopPage *shopWin = new ShopPage();
                loggedInUsername = inputUsername;
                panel *p = new panel(loggedInUsername);
                shopWin->setAttribute(Qt::WA_DeleteOnClose);
                shopWin->show();
                this->close();
            }
            else if (status == 1) {
                QMessageBox::information(this, "موفق", "ورود ادمین موفقیت‌آمیز بود!");
                Adminpage *adminWin = new Adminpage();
                adminWin->setAttribute(Qt::WA_DeleteOnClose);
                adminWin->show();
                this->close();
            }
            else if (status == 2) {  // رستوراندار
                loggedInUsername = inputUsername;  // مقداردهی متغیر سراسری
                QMessageBox::information(this, "موفق", "ورود رستوراندار موفقیت‌آمیز بود!");
                Restaurateurpage *rstrwin = new Restaurateurpage();
                rstrwin->setAttribute(Qt::WA_DeleteOnClose);
                rstrwin->show();
                this->close();
            }
            else if (status == 3) {
                errormsg("🚫شما دسترسی ندارید زیرا بلاک شده‌اید!!");
            }
        }
        else {
            errormsg("نام کاربری یا رمز عبور اشتباه می باشد!");
        }

        db.close();
    });
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
