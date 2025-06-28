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
        LoginWindow->resize(657, 427);
        verticalLayoutWidget = new QWidget(LoginWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 30, 366, 353));
        verticalLayoutWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        loginlbl = new QLabel(verticalLayoutWidget);
        loginlbl->setObjectName("loginlbl");
        loginlbl->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        loginlbl->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"text-align:center;"));
        loginlbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(loginlbl);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        username = new QLineEdit(verticalLayoutWidget);
        username->setObjectName("username");
        username->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        username->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:black;\n"
"color:orange;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid orange;"));
        username->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(username);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName("password");
        password->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        password->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:black;\n"
"color:orange;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid orange;"));
        password->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(password);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        submit = new QPushButton(verticalLayoutWidget);
        submit->setObjectName("submit");
        submit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        submit->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:lightgreen;\n"
"color:green;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));

        verticalLayout->addWidget(submit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        frame = new QFrame(LoginWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-20, 0, 691, 431));
        frame->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        frame->setStyleSheet(QString::fromUtf8(" background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 5, 0, 255), stop:1 rgba(10, 255, 255, 255))"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(frame);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(40, 20, 71, 41));
        backbtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:#df3079;\n"
"color:#1d2427;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));
        frame->raise();
        verticalLayoutWidget->raise();

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
