/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QTableWidget *tableWidget;
    QFrame *frame;
    QPushButton *backbtn;
    QLabel *label;

    void setupUi(QWidget *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName("history");
        history->resize(800, 500);
        history->setMinimumSize(QSize(800, 500));
        history->setMaximumSize(QSize(800, 500));
        tableWidget = new QTableWidget(history);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(360, 70, 371, 381));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 59, 14);\n"
"border-radius:8px"));
        frame = new QFrame(history);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 801, 501));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/historybg.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(history);
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
        label = new QLabel(history);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 20, 151, 41));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 59, 14);\n"
"border-radius:8px;\n"
"\n"
"font: 800 9pt \"IRANYekan\";"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame->raise();
        tableWidget->raise();
        backbtn->raise();
        label->raise();

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QWidget *history)
    {
        history->setWindowTitle(QCoreApplication::translate("history", "Form", nullptr));
        backbtn->setText(QCoreApplication::translate("history", "<", nullptr));
        label->setText(QCoreApplication::translate("history", "\330\252\330\247\330\261\333\214\330\256\332\206\331\207 \333\214 \330\263\331\201\330\247\330\261\330\264\330\247\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
