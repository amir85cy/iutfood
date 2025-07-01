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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Adminpage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *taiidbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Adminpage)
    {
        if (Adminpage->objectName().isEmpty())
            Adminpage->setObjectName("Adminpage");
        Adminpage->resize(800, 600);
        centralwidget = new QWidget(Adminpage);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, -20, 231, 131));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 70, 781, 471));
        taiidbtn = new QPushButton(centralwidget);
        taiidbtn->setObjectName("taiidbtn");
        taiidbtn->setGeometry(QRect(10, 30, 141, 29));
        Adminpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Adminpage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Adminpage->setMenuBar(menubar);
        statusbar = new QStatusBar(Adminpage);
        statusbar->setObjectName("statusbar");
        Adminpage->setStatusBar(statusbar);

        retranslateUi(Adminpage);

        QMetaObject::connectSlotsByName(Adminpage);
    } // setupUi

    void retranslateUi(QMainWindow *Adminpage)
    {
        Adminpage->setWindowTitle(QCoreApplication::translate("Adminpage", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Adminpage", "\331\204\333\214\330\263\330\252 \330\261\330\263\330\252\331\210\330\261\330\247\331\206 \331\207\330\247", nullptr));
        taiidbtn->setText(QCoreApplication::translate("Adminpage", "\330\252\330\247\333\214\333\214\330\257 \330\257\330\261\330\256\331\210\330\247\330\263\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adminpage: public Ui_Adminpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
