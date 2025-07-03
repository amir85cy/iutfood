#include "panel.h"
#include "iutfood_firstpage.h"
#include "shoppage.h"
#include "ui_panel.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

panel::panel(const QString &username, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::panel)
    , currentUsername(username)
{
    ui->setupUi(this);
    qDebug() << currentUsername;

    // دکمه بازگشت
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });

    // نمایش اطلاعات کاربر
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "user_conn");
    db.setDatabaseName("users.db");
    if (db.open()) {
        QSqlQuery query(db);
        QString naghsh;
        query.prepare("SELECT name, username, email, status FROM users WHERE username = ?");
        query.addBindValue(currentUsername);
        if(query.value(3).toInt()==0){naghsh="کاربر عادی";}
        if(query.value(3).toInt()==2){naghsh="رستوراندار";}
        if(query.value(3).toInt()==1){naghsh="ادمین ";}
        if(query.value(3).toInt()==3){naghsh="کاربر بلاک شده ";}
        if (query.exec() && query.next()) {
            QString info = QString("نام: %1\nیوزرنیم: %2\nایمیل: %3\nنقش: %4")
                               .arg(query.value(0).toString())
                               .arg(query.value(1).toString())
                               .arg(query.value(2).toString())
                               .arg(naghsh);
            ui->detail->setText(info);
        } else {
            ui->detail->setText("کاربر یافت نشد.");
        }
        db.close();
    } else {
        ui->detail->setText("اتصال به دیتابیس users.db برقرار نشد.");
    }

    // ثبت رستوران
    connect(ui->pushButton, &QPushButton::clicked, this, [=]() {
        QString name = ui->name->text();
        QString address = ui->address->toPlainText();
        QString type = ui->type->currentText();

        if (name.isEmpty() || address.isEmpty()) {
            QMessageBox::warning(this, "خطا", "لطفاً تمام فیلدها را پر کنید.");
            return;
        }

        // 🔰 گرفتن تایید از کاربر
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "تأیید ثبت", "آیا از ثبت این رستوران اطمینان دارید؟(با این کار نقش شما از کاربر عادی به رستوراندار تغییر خواهد کرد و دیگر به پنل کاربران عادی دسترسی نخواهید داشت)",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply != QMessageBox::Yes) {
            return; // کاربر تأیید نکرد، خروج
        }

        // ذخیره اطلاعات در دیتابیس restaurants
        QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE", "restaurant_conn");
        db1.setDatabaseName("restaurant.db");
        if (db1.open()) {
            QSqlQuery query(db1);
            query.prepare("INSERT INTO restaurant (name, type, rate, username, address,status) VALUES (?, ?, ?, ?, ?,?)");
            query.addBindValue(name);
            query.addBindValue(type);
            query.addBindValue(3); // امتیاز اولیه
            query.addBindValue(currentUsername);
            query.addBindValue(address);
            query.addBindValue(1);

            if (!query.exec()) {
                QMessageBox::critical(this, "خطا", "ثبت رستوران انجام نشد:\n" + query.lastError().text());
                db1.close();
                return;
            }
            db1.close();
        } else {
            QMessageBox::critical(this, "خطا", "اتصال به دیتابیس restaurants.db برقرار نشد.");
            return;
        }

        // بروزرسانی وضعیت کاربر در users.db
        QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "user_update_conn");
        db2.setDatabaseName("users.db");
        if (db2.open()) {
            QSqlQuery query(db2);
            query.prepare("UPDATE users SET status = 2 WHERE username = ?");
            query.addBindValue(currentUsername);
            if (!query.exec()) {
                QMessageBox::warning(this, "خطا", "بروزرسانی وضعیت کاربر انجام نشد.");
            }
            db2.close();
        }

        QMessageBox::information(this, "موفقیت", "رستوران با موفقیت ثبت شد.");
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });
}
panel::~panel()
{
    delete ui;
}
