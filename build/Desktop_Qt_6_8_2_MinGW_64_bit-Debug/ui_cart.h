/********************************************************************************
** Form generated from reading UI file 'cart.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CART_H
#define UI_CART_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cart
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *sum;
    QFrame *frame;
    QPushButton *backbtn;
    QPushButton *confirmbtn;
    QPushButton *deletebtn;

    void setupUi(QWidget *cart)
    {
        if (cart->objectName().isEmpty())
            cart->setObjectName("cart");
        cart->setEnabled(true);
        cart->resize(800, 500);
        cart->setMinimumSize(QSize(800, 500));
        cart->setMaximumSize(QSize(800, 500));
        cart->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(cart);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 798, 500));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(60, 80, 681, 370));
        tableWidget->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        tableWidget->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
        tableWidget->setTextElideMode(Qt::TextElideMode::ElideLeft);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 30, 100, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Morabba")});
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(200, 255, 255);\n"
"padding:5px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 450, 81, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Morabba")});
        font1.setPointSize(11);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(222, 222, 222);\n"
"padding:5px;"));
        sum = new QLabel(centralwidget);
        sum->setObjectName("sum");
        sum->setGeometry(QRect(60, 450, 141, 51));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        sum->setFont(font2);
        sum->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 222, 222);\n"
"color:black;\n"
"padding:5px;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 800, 500));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 85, 255);\n"
"background-color: rgb(0, 0, 127);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(frame);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(10, 10, 31, 29));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("padding:2px;\n"
"\n"
"background-color: rgb(255, 39, 79);\n"
"border:0px solid;\n"
"color:black;\n"
"font: 900 9pt \"IRANYekanFN\";\n"
"border-radius:5px;"));
        confirmbtn = new QPushButton(centralwidget);
        confirmbtn->setObjectName("confirmbtn");
        confirmbtn->setGeometry(QRect(280, 448, 121, 51));
        confirmbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        confirmbtn->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"\n"
"background-color: rgb(85, 255, 127);\n"
"color:black;\n"
"border:0px;"));
        deletebtn = new QPushButton(centralwidget);
        deletebtn->setObjectName("deletebtn");
        deletebtn->setGeometry(QRect(612, 460, 121, 29));
        deletebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deletebtn->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"background-color:red;\n"
"color:black;"));
        frame->raise();
        tableWidget->raise();
        label->raise();
        label_2->raise();
        sum->raise();
        confirmbtn->raise();
        deletebtn->raise();

        retranslateUi(cart);

        QMetaObject::connectSlotsByName(cart);
    } // setupUi

    void retranslateUi(QWidget *cart)
    {
        cart->setWindowTitle(QCoreApplication::translate("cart", "Sabad", nullptr));
        label->setText(QCoreApplication::translate("cart", "\330\263\330\250\330\257 \330\256\330\261\333\214\330\257", nullptr));
        label_2->setText(QCoreApplication::translate("cart", "\331\205\330\254\331\205\331\210\330\271 :", nullptr));
        sum->setText(QCoreApplication::translate("cart", "0000", nullptr));
        backbtn->setText(QCoreApplication::translate("cart", "<", nullptr));
        confirmbtn->setText(QCoreApplication::translate("cart", "\330\253\330\250\330\252 \330\263\331\201\330\247\330\261\330\264 ", nullptr));
        deletebtn->setText(QCoreApplication::translate("cart", "\330\255\330\260\331\201 \330\247\330\262 \330\263\330\250\330\257 \330\256\330\261\333\214\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cart: public Ui_cart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CART_H
