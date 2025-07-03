/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adminpage
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *gotorsts;
    QPushButton *gotoedituser;
    QPushButton *gotoreports;
    QWidget *widget;
    QPushButton *exitbtn;

    void setupUi(QWidget *Adminpage)
    {
        if (Adminpage->objectName().isEmpty())
            Adminpage->setObjectName("Adminpage");
        Adminpage->resize(800, 500);
        Adminpage->setMinimumSize(QSize(800, 500));
        Adminpage->setMaximumSize(QSize(800, 500));
        Adminpage->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Adminpage);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 40, 411, 101));
        label->setStyleSheet(QString::fromUtf8("color:rgb(33, 33, 33);\n"
"font-family:Rokh;\n"
"border-radius:50px;\n"
"font-size:40px;\n"
"text-align:center;\n"
"background-color:#e6d8bf;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayoutWidget = new QWidget(Adminpage);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 160, 781, 86));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gotorsts = new QPushButton(horizontalLayoutWidget);
        gotorsts->setObjectName("gotorsts");
        gotorsts->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotorsts->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: qlineargradient(\n"
"    x1:0, y1:0, x2:1, y2:0,\n"
"    stop:0 #0099F7,\n"
"    stop:1 #F11712\n"
");\n"
"\n"
"color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"padding:20px;\n"
""));

        horizontalLayout->addWidget(gotorsts);

        gotoedituser = new QPushButton(horizontalLayoutWidget);
        gotoedituser->setObjectName("gotoedituser");
        gotoedituser->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotoedituser->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: qlineargradient(\n"
"    x1:0, y1:0, x2:1, y2:0,\n"
"    stop:0 #c2e59c,\n"
"    stop:1 #64b3f4\n"
");\n"
"\n"
"color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"padding:20px;\n"
""));

        horizontalLayout->addWidget(gotoedituser);

        gotoreports = new QPushButton(horizontalLayoutWidget);
        gotoreports->setObjectName("gotoreports");
        gotoreports->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotoreports->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color: qlineargradient(\n"
"    x1:0, y1:0, x2:1, y2:0,\n"
"    stop:0 #834d9b,\n"
"    stop:1 #d04ed6\n"
");\n"
"\n"
"color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"padding:20px;\n"
""));

        horizontalLayout->addWidget(gotoreports);

        widget = new QWidget(Adminpage);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-1, -1, 801, 501));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/adminpagebg.png);"));
        exitbtn = new QPushButton(Adminpage);
        exitbtn->setObjectName("exitbtn");
        exitbtn->setGeometry(QRect(630, 10, 158, 41));
        exitbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitbtn->setStyleSheet(QString::fromUtf8("padding:5px;\n"
"border:5px solid red;\n"
"background-color: rgb(255, 170, 255);\n"
"color:black;\n"
"font: 900 8pt \"Rokh\";\n"
"border-radius:15px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #cb2d3e, stop:1 #ef473a);\n"
"\n"
"\n"
""));
        widget->raise();
        label->raise();
        horizontalLayoutWidget->raise();
        exitbtn->raise();

        retranslateUi(Adminpage);

        QMetaObject::connectSlotsByName(Adminpage);
    } // setupUi

    void retranslateUi(QWidget *Adminpage)
    {
        Adminpage->setWindowTitle(QCoreApplication::translate("Adminpage", "Admin", nullptr));
        label->setText(QCoreApplication::translate("Adminpage", "\330\247\330\257\331\205\333\214\331\206 \330\271\330\262\333\214\330\262 \330\256\331\210\330\264 \330\242\331\205\330\257\333\214\330\257", nullptr));
        gotorsts->setText(QCoreApplication::translate("Adminpage", "\330\261\330\263\330\252\331\210\330\261\330\247\331\206 \331\207\330\247 ", nullptr));
        gotoedituser->setText(QCoreApplication::translate("Adminpage", "\331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\330\261\330\250\330\261\330\247\331\206", nullptr));
        gotoreports->setText(QCoreApplication::translate("Adminpage", "\330\263\331\201\330\247\330\261\330\264\330\247\330\252 \331\210 \332\257\330\262\330\247\330\261\330\264\330\247\330\252", nullptr));
        exitbtn->setText(QCoreApplication::translate("Adminpage", "\330\256\330\261\331\210\330\254 \330\247\330\262 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adminpage: public Ui_Adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
