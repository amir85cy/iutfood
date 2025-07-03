/********************************************************************************
** Form generated from reading UI file 'peygiri.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEYGIRI_H
#define UI_PEYGIRI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_peygiri
{
public:
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QSpinBox *spinBox;
    QFrame *frame;
    QPushButton *backbtn;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QTableWidget *statusTable;

    void setupUi(QWidget *peygiri)
    {
        if (peygiri->objectName().isEmpty())
            peygiri->setObjectName("peygiri");
        peygiri->resize(800, 500);
        pushButton = new QPushButton(peygiri);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 440, 321, 51));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"font: 900 9pt \"Rokh\";"));
        plainTextEdit = new QPlainTextEdit(peygiri);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 220, 301, 221));
        plainTextEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(peygiri);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 440, 151, 51));
        pushButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Rokh\";\n"
"border:0px solid;"));
        spinBox = new QSpinBox(peygiri);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(10, 440, 151, 51));
        spinBox->setStyleSheet(QString::fromUtf8("background-color:rgb(65, 65, 65) ;\n"
"color: rgb(0, 0, 0);\n"
"\n"
"\n"
"color: rgb(255, 255, 255);"));
        frame = new QFrame(peygiri);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -10, 800, 500));
        frame->setMinimumSize(QSize(800, 500));
        frame->setMaximumSize(QSize(800, 500));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/peygiribg.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        backbtn = new QPushButton(peygiri);
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
        label_3 = new QLabel(peygiri);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 9, 251, 71));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"\n"
"\n"
"color: rgb(0, 0, 0);\n"
"border-radius:20px;\n"
"\n"
"font: 900 19pt \"Rokh\";\n"
"padding:10px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(peygiri);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 100, 251, 71));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"\n"
"\n"
"color: rgb(0, 0, 0);\n"
"border-radius:20px;\n"
"\n"
"font: 900 19pt \"Rokh\";\n"
"padding:10px;"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(peygiri);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(500, 100, 291, 71));
        label_5->setStyleSheet(QString::fromUtf8("background-color:rgb(85, 170, 255);\n"
"\n"
"color: rgb(0, 0, 0);\n"
"border-radius:20px;\n"
"\n"
"font: 900 19pt \"Rokh\";\n"
"padding:10px;"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        line = new QFrame(peygiri);
        line->setObjectName("line");
        line->setGeometry(QRect(380, 80, 20, 421));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        statusTable = new QTableWidget(peygiri);
        statusTable->setObjectName("statusTable");
        statusTable->setGeometry(QRect(470, 220, 321, 221));
        statusTable->setStyleSheet(QString::fromUtf8("background-color:rgb(61, 61, 61);"));
        frame->raise();
        pushButton->raise();
        plainTextEdit->raise();
        pushButton_2->raise();
        spinBox->raise();
        backbtn->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        line->raise();
        statusTable->raise();

        retranslateUi(peygiri);

        QMetaObject::connectSlotsByName(peygiri);
    } // setupUi

    void retranslateUi(QWidget *peygiri)
    {
        peygiri->setWindowTitle(QCoreApplication::translate("peygiri", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("peygiri", "\342\234\205\330\252\330\255\331\210\333\214\331\204 \332\257\330\261\331\201\330\252\331\205", nullptr));
        pushButton_2->setText(QCoreApplication::translate("peygiri", "\342\234\205\330\247\330\261\330\263\330\247\331\204 \331\206\330\270\330\261", nullptr));
        backbtn->setText(QCoreApplication::translate("peygiri", "<", nullptr));
        label_3->setText(QCoreApplication::translate("peygiri", "\331\276\333\214\332\257\333\214\330\261\333\214 \330\263\331\201\330\247\330\261\330\264", nullptr));
        label_4->setText(QCoreApplication::translate("peygiri", "\330\247\330\261\330\263\330\247\331\204 \331\206\330\270\330\261", nullptr));
        label_5->setText(QCoreApplication::translate("peygiri", "\331\210\330\266\330\271\333\214\330\252 \330\263\331\201\330\247\330\261\330\264 \331\207\330\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class peygiri: public Ui_peygiri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEYGIRI_H
