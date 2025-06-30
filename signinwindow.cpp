#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QRegularExpression>
#include "signinwindow.h"
#include "ui_signinwindow.h"
#include "iutfood_firstpage.h"
void successmsg(const QString &text) {
    QMessageBox msg;
    msg.setText(text);
    msg.setIcon(QMessageBox::Information);
    msg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    QFont font("iranyekan", 12, QFont::Bold);
    msg.setFont(font);
    msg.setStyleSheet(
        "QLabel { color: green; font-size: 16px; padding: 10px; }"
        "QMessageBox { background-color: #e8ffe8; border: 2px solid #66cc66; }"
        );
    QPixmap pix(":/new/images/tik.png");
    QPixmap scaledPix = pix.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    msg.setIconPixmap(scaledPix);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
bool isStrongPassword(const QString &password) {
    if (password.length() < 8)
        return false;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSymbol = false;

    for (const QChar &ch : password) {
        if (ch.isUpper())
            hasUpper = true;
        else if (ch.isLower())
            hasLower = true;
        else if (ch.isDigit())
            hasDigit = true;
        else
            hasSymbol = true;
    }

    return hasUpper && hasLower && hasDigit && hasSymbol;
}

bool isEmailDuplicate(const QString &email) {
    QSqlDatabase db = QSqlDatabase::database();  // استفاده از اتصال موجود

    if (!db.isOpen()) {
        qDebug() << "دیتابیس هنوز باز نشده!";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT 1 FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        //qDebug() << "خطا در کوئری:" << query.lastError().text();
        return false;
    }

    return query.next();  // اگه رکوردی پیدا شد یعنی ایمیل تکراریه
}

bool isEnglishOnly(const QString &text) {
    QRegularExpression regex(R"(^[A-Za-z0-9]+$)");
    return regex.match(text).hasMatch();
}

bool isValidEmail(const QString &email) {
    QRegularExpression regex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return regex.match(email).hasMatch();
}
void errormsg(const QString &matn) {
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


Signinwindow::Signinwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Signinwindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });
    // ذخیره ی اطلاعات
    ui->password->setEchoMode(QLineEdit::Password);
    ui->password2->setEchoMode(QLineEdit::Password);

    connect(ui->submit, &QPushButton::clicked, this, [=]() {
        QString username = ui->username->text().trimmed();
        QString password = ui->password->text().trimmed();
        QString password2 = ui->password2->text().trimmed();
        QString name = ui->name->text().trimmed();
        QString email = ui->email->text().trimmed();

        // خالی بودن هر فیلد

        if (name.isEmpty()) {
            errormsg("فیلد نام نباید خالی باشد! ");
            return;
        }
        if (username.isEmpty()) {
            errormsg("فیلد نام کاربری نباید خالی باشد! ");
            return;
        }

        if (email.isEmpty()) {
            errormsg("فیلد ایمیل نباید خالی باشد! ");
            return;
        }

        if (password.isEmpty()) {
            errormsg("فیلد رمز عبور نباید خالی باشد! ");
            return;
        }
        if (password2.isEmpty()) {
            errormsg("فیلد تکرار رمز عبور نباید خالی باشد! ");
            return;
        }

        /////////////////////////////////////////////////////////////////////////////////////
        if(password2 != password){
            errormsg("تکرار رمز عبور با رمز عبور برابر نیست !!");
            return;
        }

        if (!isValidEmail(email)) {
            errormsg("فرمت ایمیل معتبر نیست!");
            return;
        }


        if (!isEnglishOnly(username)) {
            errormsg("نام کاربری  باید تنها شامل حروف انگلیسی یا عدد باشد!");
            return;
        }

        if (isEmailDuplicate(email)) {
            errormsg("این ایمیل قبلاً استفاده شده است!");
            return;
        }
        if (!isStrongPassword(password)) {
            errormsg("رمز عبور باید حداقل ۸ کاراکتر و شامل حروف بزرگ، کوچک، عدد و یک کاراکتر خاص باشد.");
            return;
        }
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("users.db");

        if (!db.open()) {
            QMessageBox::critical(this, "خطا", "اتصال به دیتابیس انجام نشد!");
            return;
        }

        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT * FROM users WHERE username = :username");
        checkQuery.bindValue(":username", username);
        if (checkQuery.exec() && checkQuery.next()) {
            errormsg("!! با این نام کاربری قبلا ثبت نام شده");
            db.close();
            return;
        }
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO users (name, username, password, email , status) VALUES (:name, :username, :password, :email , :status)");
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":username", username);
        insertQuery.bindValue(":password", password);
        insertQuery.bindValue(":email", email);
        insertQuery.bindValue(":status", 0);


        if (insertQuery.exec()) {
            successmsg("ثبت‌نام با موفقیت انجام شد 🎉");
            // ممکنه بخوای این پنجره رو ببندی یا بری به login:
            // this->close();
        } else {
            QMessageBox::critical(this, "خطا", "ثبت ‌نام انجام نشد!");
        }

        db.close();
    });
}

Signinwindow::~Signinwindow()
{
    delete ui;
}
