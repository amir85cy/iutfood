/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_panel
{
public:
    QLabel *label;
    QTextBrowser *detail;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *name;
    QTextEdit *address;
    QComboBox *type;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;
    QPushButton *backbtn;

    void setupUi(QWidget *panel)
    {
        if (panel->objectName().isEmpty())
            panel->setObjectName("panel");
        panel->resize(800, 500);
        panel->setMinimumSize(QSize(800, 500));
        panel->setMaximumSize(QSize(800, 500));
        panel->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(panel);
        label->setObjectName("label");
        label->setGeometry(QRect(530, 20, 110, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Morabba")});
        font.setPointSize(13);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        detail = new QTextBrowser(panel);
        detail->setObjectName("detail");
        detail->setGeometry(QRect(430, 90, 301, 371));
        detail->setStyleSheet(QString::fromUtf8("font: 900 15pt \"IRANYekan\";\n"
"\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(panel);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 420, 280, 50));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(180, 255, 180);\n"
"\n"
"font: 900 9pt \"IRANYekan\";\n"
"border-radius:10px;"));
        frame = new QFrame(panel);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, 0, 801, 501));
        frame->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(25, 25, 255, 255), stop:1 rgba(255, 25, 255, 255));"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        name = new QLineEdit(panel);
        name->setObjectName("name");
        name->setGeometry(QRect(60, 100, 191, 28));
        name->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);"));
        address = new QTextEdit(panel);
        address->setObjectName("address");
        address->setGeometry(QRect(60, 180, 281, 111));
        address->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 36, 36);"));
        type = new QComboBox(panel);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(60, 320, 141, 28));
        type->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        type->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        type->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";\n"
"background-color: rgb(36, 36, 36);"));
        type->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
        label_2 = new QLabel(panel);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 100, 91, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";\n"
"\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(panel);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 150, 121, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";\n"
"\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(panel);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 320, 141, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";\n"
"\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(panel);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(150, 20, 121, 60));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        line = new QFrame(panel);
        line->setObjectName("line");
        line->setGeometry(QRect(370, 0, 41, 501));
        line->setStyleSheet(QString::fromUtf8(""));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        backbtn = new QPushButton(panel);
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
        frame->raise();
        label->raise();
        detail->raise();
        pushButton->raise();
        name->raise();
        address->raise();
        type->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        line->raise();
        backbtn->raise();

        retranslateUi(panel);

        QMetaObject::connectSlotsByName(panel);
    } // setupUi

    void retranslateUi(QWidget *panel)
    {
        panel->setWindowTitle(QCoreApplication::translate("panel", "Form", nullptr));
        label->setText(QCoreApplication::translate("panel", "\331\276\331\206\331\204 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        detail->setHtml(QCoreApplication::translate("panel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'IRANYekan'; font-size:15pt; font-weight:900; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt; font-weight:400;\">\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 : <br />\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214 :<br />\330\247\333\214\331\205\333\214\331\204 :<br />\331\206\331\202\330\264 :</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0p"
                        "x; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("panel", "\330\261\330\263\330\252\331\210\330\261\330\247\331\206 \330\257\330\247\330\261\331\205 !", nullptr));
        type->setItemText(0, QCoreApplication::translate("panel", "\330\263\331\206\330\252\333\214", nullptr));
        type->setItemText(1, QCoreApplication::translate("panel", "\331\201\330\261\331\206\332\257\333\214", nullptr));
        type->setItemText(2, QCoreApplication::translate("panel", "\331\201\330\263\330\252 \331\201\331\210\330\257", nullptr));
        type->setItemText(3, QCoreApplication::translate("panel", "\330\256\330\247\331\206\332\257\333\214", nullptr));
        type->setItemText(4, QCoreApplication::translate("panel", "\330\247\333\214\330\261\330\247\331\206\333\214", nullptr));

        label_2->setText(QCoreApplication::translate("panel", "\331\206\330\247\331\205 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        label_3->setText(QCoreApplication::translate("panel", "\330\242\330\257\330\261\330\263 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        label_4->setText(QCoreApplication::translate("panel", "\330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214 \330\261\330\263\330\252\331\210\330\261\330\247\331\206 ", nullptr));
        label_5->setText(QCoreApplication::translate("panel", "\330\253\330\250\330\252 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        backbtn->setText(QCoreApplication::translate("panel", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class panel: public Ui_panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
