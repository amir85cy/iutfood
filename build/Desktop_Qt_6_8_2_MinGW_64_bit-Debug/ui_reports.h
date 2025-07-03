/********************************************************************************
** Form generated from reading UI file 'reports.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTS_H
#define UI_REPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Reports
{
public:
    QWidget *centralwidget;
    QListWidget *reportlist;
    QPushButton *backbtn;
    QListWidget *orderlist;
    QLabel *label_2;
    QFrame *frame;
    QLabel *label_3;

    void setupUi(QMainWindow *Reports)
    {
        if (Reports->objectName().isEmpty())
            Reports->setObjectName("Reports");
        Reports->resize(800, 500);
        Reports->setMinimumSize(QSize(800, 500));
        Reports->setMaximumSize(QSize(800, 500));
        centralwidget = new QWidget(Reports);
        centralwidget->setObjectName("centralwidget");
        reportlist = new QListWidget(centralwidget);
        reportlist->setObjectName("reportlist");
        reportlist->setGeometry(QRect(110, 20, 251, 351));
        reportlist->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/listbg.jpg);\n"
"\n"
"border-radius:10px;"));
        backbtn = new QPushButton(centralwidget);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(20, 10, 31, 29));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("padding:2px;\n"
"\n"
"background-color: rgb(255, 39, 79);\n"
"border:0px solid;\n"
"color:black;\n"
"font: 900 9pt \"IRANYekanFN\";\n"
"border-radius:5px;"));
        orderlist = new QListWidget(centralwidget);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditSelectAll));
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(orderlist);
        __qlistwidgetitem->setIcon(icon);
        orderlist->setObjectName("orderlist");
        orderlist->setGeometry(QRect(400, 80, 261, 381));
        orderlist->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/listbg.jpg);\n"
"\n"
"border-radius:10px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 330, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rokh")});
        font.setPointSize(10);
        font.setWeight(QFont::Black);
        font.setItalic(false);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 900 10pt \"Rokh\";"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 800, 500));
        frame->setMinimumSize(QSize(800, 500));
        frame->setMaximumSize(QSize(800, 500));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/reportsbg.png);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(640, 40, 121, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 900 10pt \"Rokh\";"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Reports->setCentralWidget(centralwidget);
        frame->raise();
        reportlist->raise();
        backbtn->raise();
        orderlist->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Reports);

        QMetaObject::connectSlotsByName(Reports);
    } // setupUi

    void retranslateUi(QMainWindow *Reports)
    {
        Reports->setWindowTitle(QCoreApplication::translate("Reports", "Reports", nullptr));
        backbtn->setText(QCoreApplication::translate("Reports", "<", nullptr));

        const bool __sortingEnabled = orderlist->isSortingEnabled();
        orderlist->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = orderlist->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Reports", "\330\261\330\263\330\252\331\210\330\261\330\247\331\206 \330\247\330\271\330\270\331\205 - \332\251\330\250\330\247\330\250 \332\251\331\210\330\250\333\214\330\257\331\207 ", nullptr));
        orderlist->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("Reports", "\331\204\333\214\330\263\330\252 \332\257\330\262\330\247\330\261\330\264\330\247\330\252", nullptr));
        label_3->setText(QCoreApplication::translate("Reports", "\331\204\333\214\330\263\330\252 \330\263\331\201\330\247\330\261\330\264\330\247\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Reports: public Ui_Reports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTS_H
