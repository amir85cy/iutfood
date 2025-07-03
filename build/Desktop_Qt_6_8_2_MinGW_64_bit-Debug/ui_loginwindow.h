/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *loginlbl;
    QSpacerItem *verticalSpacer;
    QLineEdit *username;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *password;
    QSpacerItem *verticalSpacer_3;
    QPushButton *submit;
    QSpacerItem *verticalSpacer_4;
    QFrame *frame;
    QPushButton *backbtn;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 500);
        LoginWindow->setMinimumSize(QSize(800, 500));
        LoginWindow->setMaximumSize(QSize(800, 500));
        verticalLayoutWidget = new QWidget(LoginWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(420, 80, 366, 353));
        verticalLayoutWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        loginlbl = new QLabel(verticalLayoutWidget);
        loginlbl->setObjectName("loginlbl");
        loginlbl->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        loginlbl->setStyleSheet(QString::fromUtf8("color:#f1a91d;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"text-align:center;\n"
"\n"
""));
        loginlbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(loginlbl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        username = new QLineEdit(verticalLayoutWidget);
        username->setObjectName("username");
        username->setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        username->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#9d0b0b;\n"
"color:#f1a91d;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid #f1a91d;"));
        username->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(username);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName("password");
        password->setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        password->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#9d0b0b;\n"
"color:#f1a91d;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid #f1a91d;"));
        password->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(password);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        submit = new QPushButton(verticalLayoutWidget);
        submit->setObjectName("submit");
        submit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        submit->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:lightgreen;\n"
"color:white;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0#f1a91d, stop:1 red);"));

        verticalLayout->addWidget(submit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        frame = new QFrame(LoginWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 801, 501));
        frame->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        frame->setStyleSheet(QString::fromUtf8("\n"
"\n"
"border-image: url(:/new/images/loginbg.webp);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(LoginWindow);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(30, 10, 71, 41));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:#f1a91d;\n"
"color:#1d2427;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));
        frame->raise();
        verticalLayoutWidget->raise();
        backbtn->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        loginlbl->setText(QCoreApplication::translate("LoginWindow", "\331\210\330\261\331\210\330\257", nullptr));
        username->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        submit->setText(QCoreApplication::translate("LoginWindow", "\331\210\330\261\331\210\330\257", nullptr));
        backbtn->setText(QCoreApplication::translate("LoginWindow", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
