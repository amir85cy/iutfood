/********************************************************************************
** Form generated from reading UI file 'customerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERPAGE_H
#define UI_CUSTOMERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Customerpage
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Customerpage)
    {
        if (Customerpage->objectName().isEmpty())
            Customerpage->setObjectName("Customerpage");
        Customerpage->resize(800, 600);
        centralwidget = new QWidget(Customerpage);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 70, 63, 20));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(320, 230, 256, 192));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 100, 83, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 190, 83, 29));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(120, 250, 83, 29));
        Customerpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Customerpage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Customerpage->setMenuBar(menubar);
        statusbar = new QStatusBar(Customerpage);
        statusbar->setObjectName("statusbar");
        Customerpage->setStatusBar(statusbar);

        retranslateUi(Customerpage);

        QMetaObject::connectSlotsByName(Customerpage);
    } // setupUi

    void retranslateUi(QMainWindow *Customerpage)
    {
        Customerpage->setWindowTitle(QCoreApplication::translate("Customerpage", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("Customerpage", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("Customerpage", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Customerpage", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Customerpage", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Customerpage: public Ui_Customerpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERPAGE_H
