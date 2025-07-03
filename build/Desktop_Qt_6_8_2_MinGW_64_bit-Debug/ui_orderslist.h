/********************************************************************************
** Form generated from reading UI file 'orderslist.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERSLIST_H
#define UI_ORDERSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orderslist
{
public:
    QPushButton *btnConfirm;
    QPushButton *btnStartPreparing;
    QPushButton *btnPreparing;
    QPushButton *btnDelivered;
    QFrame *frame;
    QPushButton *backbtn;
    QTableWidget *tableWidget;

    void setupUi(QWidget *orderslist)
    {
        if (orderslist->objectName().isEmpty())
            orderslist->setObjectName("orderslist");
        orderslist->resize(800, 500);
        orderslist->setStyleSheet(QString::fromUtf8(""));
        btnConfirm = new QPushButton(orderslist);
        btnConfirm->setObjectName("btnConfirm");
        btnConfirm->setGeometry(QRect(90, 370, 91, 81));
        btnConfirm->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnConfirm->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        btnStartPreparing = new QPushButton(orderslist);
        btnStartPreparing->setObjectName("btnStartPreparing");
        btnStartPreparing->setGeometry(QRect(260, 380, 91, 81));
        btnStartPreparing->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnStartPreparing->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        btnPreparing = new QPushButton(orderslist);
        btnPreparing->setObjectName("btnPreparing");
        btnPreparing->setGeometry(QRect(430, 380, 101, 81));
        btnPreparing->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPreparing->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        btnDelivered = new QPushButton(orderslist);
        btnDelivered->setObjectName("btnDelivered");
        btnDelivered->setGeometry(QRect(600, 380, 121, 141));
        btnDelivered->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDelivered->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border: none;"));
        frame = new QFrame(orderslist);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 800, 500));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/orderlistbg.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(orderslist);
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
        tableWidget = new QTableWidget(orderslist);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 30, 640, 290));
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 250, 93);\n"
"border-radius:8px;\n"
"color:black;"));
        frame->raise();
        btnConfirm->raise();
        btnStartPreparing->raise();
        btnPreparing->raise();
        btnDelivered->raise();
        backbtn->raise();
        tableWidget->raise();

        retranslateUi(orderslist);

        QMetaObject::connectSlotsByName(orderslist);
    } // setupUi

    void retranslateUi(QWidget *orderslist)
    {
        orderslist->setWindowTitle(QCoreApplication::translate("orderslist", "Orders", nullptr));
#if QT_CONFIG(tooltip)
        btnConfirm->setToolTip(QCoreApplication::translate("orderslist", "\330\252\330\247\333\214\333\214\330\257", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConfirm->setText(QString());
#if QT_CONFIG(tooltip)
        btnStartPreparing->setToolTip(QCoreApplication::translate("orderslist", "\330\264\330\261\331\210\330\271 \330\242\331\205\330\247\330\257\331\207 \330\263\330\247\330\262\333\214", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStartPreparing->setText(QString());
#if QT_CONFIG(tooltip)
        btnPreparing->setToolTip(QCoreApplication::translate("orderslist", "\330\257\330\261 \330\255\330\247\331\204 \330\242\331\205\330\247\330\257\331\207 \330\263\330\247\330\262\333\214", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPreparing->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelivered->setToolTip(QCoreApplication::translate("orderslist", "\330\247\330\261\330\263\330\247\331\204 \330\264\330\257", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelivered->setText(QString());
        backbtn->setText(QCoreApplication::translate("orderslist", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orderslist: public Ui_orderslist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERSLIST_H
