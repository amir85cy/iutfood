#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QMessageBox>
#include "edituser.h"
#include "ui_edituser.h"
#include "adminpage.h"
#include <QDir>
#include <QDebug>


void Edituser::deleteSelectedUser() {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "اخطار", "هیچ کاربری انتخاب نشده!");
        return;
    }

    QString line = selectedItem->text();
    int endRoleIndex = line.indexOf(')');
    QString username;
    if (endRoleIndex != -1) {
        username = line.mid(endRoleIndex + 1);
    } else {
        QMessageBox::warning(this, "خطا", "فرمت نامعتبر برای آیتم انتخاب شده.");
        return;
    }

    // تأییدیه از کاربر
    int confirm = QMessageBox::question(this, "حذف کاربر",
                                        "آیا مطمئن هستید که می‌خواهید این کاربر را حذف کنید؟",
                                        QMessageBox::Yes | QMessageBox::No);
    if (confirm != QMessageBox::Yes)
        return;

    // حذف از دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if (!db.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه‌داده ناموفق بود.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "خطا", "حذف کاربر با خطا مواجه شد:\n" + query.lastError().text());
    } else {
        delete selectedItem; // حذف از لیست ویجت
        QMessageBox::information(this, "موفق", "کاربر با موفقیت حذف شد!");
    }

    db.close();
}

void Edituser::showSelectedUserInfo() {
    // گرفتن آیتم انتخاب‌شده از لیست (مثلاً لیست یوزرنیم‌ها)
    QString selectedUsername;
    QString usernameselect;
    if (ui->listWidget->currentItem()) {
        QString line = ui->listWidget->currentItem()->text();
        int endRoleIndex = line.indexOf(')');
        if (endRoleIndex != -1) {
            // نقش: از اندیس 0 تا endRoleIndex
            QString role = line.mid(0, endRoleIndex + 1);
            // یوزرنیم: از اندیس بعد از پرانتز بسته تا انتها
            usernameselect = line.mid(endRoleIndex + 1);
        } else {
            qDebug() << "فرمت ورودی اشتباه است";
        }
    } else {
        QMessageBox::warning(this, "خطا", "هیچ کاربری انتخاب نشده است.");
        return;
    }

    // آماده‌سازی کوئری
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه‌داده ناموفق بود.");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT name, username, email, password, status FROM users WHERE username = :username");
    query.bindValue(":username", usernameselect);

    if (query.exec() && query.next()) {
        QString name = query.value(0).toString();
        QString username = query.value(1).toString();
        QString email = query.value(2).toString();
        QString password = query.value(3).toString();
        QString status = query.value(4).toString();
        QString role;
        if(query.value(4) == 0){role = "مشتری";}
        if(query.value(4) == 1){role = "ادمین";}
        if(query.value(4) == 2){role = "رستوراندار";}
        if(query.value(4) == 3){role = "کاربر بلاک شده";}
        // نمایش اطلاعات
        QString message = QString(
                              "نام: %1\n"
                              "یوزرنیم: %2\n"
                              "ایمیل: %3\n"
                              "رمزعبور: %4\n"
                              "نقش: %5"
                              ).arg(name, username, email, password, role);


        QMessageBox msg;
        msg.setText(message);
        msg.setIcon(QMessageBox::Information);
        msg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        QFont font("iranyekan", 12, QFont::Bold);
        msg.setFont(font);
        msg.setStyleSheet("QLabel { color: #3966ff; padding: 10px; text-align:center;}");

        QPushButton *okBtn = msg.addButton("فهمیدم", QMessageBox::AcceptRole);
        okBtn->setStyleSheet("padding: 3px 6px; font-family: iranyekan; font-size: 10px;");
        msg.exec();
    } else {
        QMessageBox::warning(this, "خطا", "کاربر در دیتابیس پیدا نشد.");
    }
}

void Edituser::changeUserRole(int rolenum) {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "اخطار", "هیچ آیتمی انتخاب نشده!");
        return;
    }

    // جدا کردن username
    QString line = selectedItem->text();
    int endRoleIndex = line.indexOf(')');
    QString username;
    if (endRoleIndex != -1) {
        username = line.mid(endRoleIndex + 1);
    } else {
        qDebug() << "فرمت ورودی اشتباه است";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");

    if (!db.open()) {
        QMessageBox::critical(this, "خطا", "اتصال به پایگاه‌داده ناموفق بود.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT status FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        QMessageBox::critical(this, "خطا", "اجرای کوئری با خطا مواجه شد:\n" + query.lastError().text());
        db.close();
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "خطا", "کاربر در دیتابیس پیدا نشد.");
        db.close();
        return;
    }

    if(query.value(0).toInt() == 3 && rolenum == 3){
        rolenum = 0; // اگر کاربر بلاک شده بود و دوباره خواستیم بلاکش کنیم، آنبلاک بشه
    }

    // به‌روزرسانی نقش
    query.prepare("UPDATE users SET status = :newStatus WHERE username = :username");
    query.bindValue(":newStatus", rolenum);
    query.bindValue(":username", username);

    if (!query.exec()) {
        QString errorText;
        if(rolenum == 1) errorText = "به‌روزرسانی نقش ناموفق بود:\n";
        if(rolenum == 3) errorText = "بلاک کردن کاربر ناموفق بود:\n";
        if(rolenum == 0) errorText = "آنبلاک کردن کاربر ناموفق بود:\n";
        QMessageBox::critical(this, "خطا", errorText + query.lastError().text());
    } else {
        if(rolenum == 1){
            QMessageBox::information(this, "موفق", "نقش کاربر با موفقیت تغییر کرد!");
            selectedItem->setText("(ادمین)"+username);
        }
        if(rolenum == 3){
            QMessageBox::information(this, "موفق", "کاربر با موفقیت بلاک شد!");
            selectedItem->setText("(کاربر بلاک شده)"+username);
        }
        if(rolenum == 0){
            QMessageBox::information(this, "موفق", "کاربر با موفقیت آنبلاک شد!");
            selectedItem->setText("(مشتری)"+username);
        }
    }

    db.close();
}


void Edituser::loadUsersFromDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");  // مسیر فایل دیتابیس
    qDebug() << "DB Path: " << QDir::currentPath() + "/" + db.databaseName();
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }
    QIcon icon = QIcon::fromTheme("user-available");
    QSqlQuery query("SELECT username, status FROM users");
    while (query.next()) {
        QString username = query.value(0).toString();
        QString status = query.value(1).toString();
        QString displayText;
        if(query.value(1).toInt() == 0){
            displayText = "(مشتری)" + username;
        }
        if(query.value(1).toInt() == 1){
            displayText = "(ادمین)" + username;
        }
        if(query.value(1).toInt() == 2){
            displayText = "(رستوراندار)" + username;
        }
        if(query.value(1).toInt() == 3){
            displayText = "(کاربر بلاک شده)" + username;
        }
        QListWidgetItem* item = new QListWidgetItem(icon, displayText);
        item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->listWidget->addItem(item);
    }
    db.close();
}

Edituser::Edituser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Edituser)
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
            background-color: #ffb48a;
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
    loadUsersFromDatabase();
    connect(ui->editrolebtn, &QPushButton::clicked, this, [=]() { changeUserRole(1); });
    connect(ui->blockbtn, &QPushButton::clicked, this, [=]() { changeUserRole(3); });
    connect(ui->viewbtn, &QPushButton::clicked, this, &Edituser::showSelectedUserInfo);
    connect(ui->deletebtn, &QPushButton::clicked, this, &Edituser::deleteSelectedUser);

}

Edituser::~Edituser()
{
    delete ui;
}
