/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signinwindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *signinlbl;
    QLineEdit *name;
    QLineEdit *username;
    QLineEdit *email;
    QLineEdit *password;
    QLineEdit *password2;
    QPushButton *submit;
    QFrame *frame;
    QPushButton *backbtn;

    void setupUi(QWidget *Signinwindow)
    {
        if (Signinwindow->objectName().isEmpty())
            Signinwindow->setObjectName("Signinwindow");
        Signinwindow->resize(800, 500);
        verticalLayoutWidget = new QWidget(Signinwindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 30, 222, 404));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        signinlbl = new QLabel(verticalLayoutWidget);
        signinlbl->setObjectName("signinlbl");
        signinlbl->setStyleSheet(QString::fromUtf8("color:#2f6901;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"text-align:center;\n"
"padding:10px;"));
        signinlbl->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(signinlbl);

        name = new QLineEdit(verticalLayoutWidget);
        name->setObjectName("name");
        name->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#c9ff83;\n"
"color:darkgreen;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid green;"));

        verticalLayout->addWidget(name);

        username = new QLineEdit(verticalLayoutWidget);
        username->setObjectName("username");
        username->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#c9ff83;\n"
"color:darkgreen;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid green;"));

        verticalLayout->addWidget(username);

        email = new QLineEdit(verticalLayoutWidget);
        email->setObjectName("email");
        email->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#c9ff83;\n"
"color:darkgreen;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid green;"));

        verticalLayout->addWidget(email);

        password = new QLineEdit(verticalLayoutWidget);
        password->setObjectName("password");
        password->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#c9ff83;\n"
"color:darkgreen;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid green;"));

        verticalLayout->addWidget(password);

        password2 = new QLineEdit(verticalLayoutWidget);
        password2->setObjectName("password2");
        password2->setStyleSheet(QString::fromUtf8("width:200px;\n"
"background-color:#c9ff83;\n"
"color:darkgreen;\n"
"font-family:Rokh;\n"
"padding:8px;\n"
"border-radius:10px;\n"
"border:2px solid green;"));

        verticalLayout->addWidget(password2);

        submit = new QPushButton(verticalLayoutWidget);
        submit->setObjectName("submit");
        submit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        submit->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: qlineargradient(\n"
"    x1:0, y1:0, x2:1, y2:0,\n"
"    stop:0 #4AC29A,\n"
"    stop:1 #BDFFF3\n"
");\n"
"\n"
"color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
""));

        verticalLayout->addWidget(submit);

        frame = new QFrame(Signinwindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-90, -10, 890, 510));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/photo_2025-06-30_01-52-04.jpg) 0 0 0 0 stretch stretch;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(Signinwindow);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(20, 30, 71, 41));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:lightgreen;\n"
"color:#1d2427;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));
        frame->raise();
        verticalLayoutWidget->raise();
        backbtn->raise();

        retranslateUi(Signinwindow);

        QMetaObject::connectSlotsByName(Signinwindow);
    } // setupUi

    void retranslateUi(QWidget *Signinwindow)
    {
        Signinwindow->setWindowTitle(QCoreApplication::translate("Signinwindow", "Sign In", nullptr));
        signinlbl->setText(QCoreApplication::translate("Signinwindow", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("Signinwindow", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("Signinwindow", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("Signinwindow", "\330\247\333\214\331\205\333\214\331\204", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("Signinwindow", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        password2->setPlaceholderText(QCoreApplication::translate("Signinwindow", "\330\252\332\251\330\261\330\247\330\261 \330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        submit->setText(QCoreApplication::translate("Signinwindow", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        backbtn->setText(QCoreApplication::translate("Signinwindow", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signinwindow: public Ui_Signinwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
