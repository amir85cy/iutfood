/********************************************************************************
** Form generated from reading UI file 'ownerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OWNERPAGE_H
#define UI_OWNERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ownerpage
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Ownerpage)
    {
        if (Ownerpage->objectName().isEmpty())
            Ownerpage->setObjectName("Ownerpage");
        Ownerpage->resize(800, 600);
        centralwidget = new QWidget(Ownerpage);
        centralwidget->setObjectName("centralwidget");
        Ownerpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Ownerpage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Ownerpage->setMenuBar(menubar);
        statusbar = new QStatusBar(Ownerpage);
        statusbar->setObjectName("statusbar");
        Ownerpage->setStatusBar(statusbar);

        retranslateUi(Ownerpage);

        QMetaObject::connectSlotsByName(Ownerpage);
    } // setupUi

    void retranslateUi(QMainWindow *Ownerpage)
    {
        Ownerpage->setWindowTitle(QCoreApplication::translate("Ownerpage", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ownerpage: public Ui_Ownerpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OWNERPAGE_H
