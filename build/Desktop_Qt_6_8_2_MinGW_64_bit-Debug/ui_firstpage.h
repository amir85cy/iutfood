/********************************************************************************
** Form generated from reading UI file 'firstpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTPAGE_H
#define UI_FIRSTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstpage
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *customerbtn;
    QPushButton *adminbtn;
    QPushButton *ownerbtn;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *firstpage)
    {
        if (firstpage->objectName().isEmpty())
            firstpage->setObjectName("firstpage");
        firstpage->resize(800, 600);
        centralwidget = new QWidget(firstpage);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 250, 781, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        customerbtn = new QPushButton(horizontalLayoutWidget);
        customerbtn->setObjectName("customerbtn");

        horizontalLayout->addWidget(customerbtn);

        adminbtn = new QPushButton(horizontalLayoutWidget);
        adminbtn->setObjectName("adminbtn");

        horizontalLayout->addWidget(adminbtn);

        ownerbtn = new QPushButton(horizontalLayoutWidget);
        ownerbtn->setObjectName("ownerbtn");
        ownerbtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 250, 0, 255), stop:1 rgba(25, 255, 255, 255));\n"
"color: rgb(0, 0, 0);\n"
"\n"
"border:0px solid ;\n"
"padding:10px;\n"
"border-radius:10px;"));

        horizontalLayout->addWidget(ownerbtn);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 100, 231, 141));
        label->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        firstpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(firstpage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        firstpage->setMenuBar(menubar);
        statusbar = new QStatusBar(firstpage);
        statusbar->setObjectName("statusbar");
        firstpage->setStatusBar(statusbar);

        retranslateUi(firstpage);

        QMetaObject::connectSlotsByName(firstpage);
    } // setupUi

    void retranslateUi(QMainWindow *firstpage)
    {
        firstpage->setWindowTitle(QCoreApplication::translate("firstpage", "MainWindow", nullptr));
        customerbtn->setText(QCoreApplication::translate("firstpage", "CustomerPage", nullptr));
        adminbtn->setText(QCoreApplication::translate("firstpage", "AdminPage", nullptr));
        ownerbtn->setText(QCoreApplication::translate("firstpage", "OwnerPage", nullptr));
        label->setText(QCoreApplication::translate("firstpage", "\330\247\330\257\331\205\333\214\331\206 \330\271\330\262\333\214\330\262 \330\256\331\210\330\264 \330\242\331\205\330\257\333\214\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firstpage: public Ui_firstpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTPAGE_H
