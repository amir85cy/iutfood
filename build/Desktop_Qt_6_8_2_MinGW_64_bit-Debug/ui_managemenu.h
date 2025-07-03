/********************************************************************************
** Form generated from reading UI file 'managemenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENU_H
#define UI_MANAGEMENU_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_managemenu
{
public:
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *priceEdit;
    QComboBox *typeEdit;
    QLineEdit *nameEdit;
    QPushButton *addbtn;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QPushButton *deletebtn;
    QPushButton *backbtn;

    void setupUi(QWidget *managemenu)
    {
        if (managemenu->objectName().isEmpty())
            managemenu->setObjectName("managemenu");
        managemenu->resize(800, 500);
        managemenu->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        managemenu->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(managemenu);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 811, 511));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/managemenubg.png);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(managemenu);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 20, 342, 421));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        priceEdit = new QLineEdit(verticalLayoutWidget);
        priceEdit->setObjectName("priceEdit");
        priceEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 85, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"padding:10px;\n"
"font: 300 9pt \"IRANYekan\";\n"
"border:1px solid black;\n"
"width:80px;\n"
"height:20px;"));

        horizontalLayout->addWidget(priceEdit);

        typeEdit = new QComboBox(verticalLayoutWidget);
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->addItem(QString());
        typeEdit->setObjectName("typeEdit");
        typeEdit->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        typeEdit->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        typeEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 85, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"padding:10px;\n"
"font: 300 9pt \"IRANYekan\";\n"
"border:1px solid black;\n"
"width:80px;\n"
"height:20px;"));
        typeEdit->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
        typeEdit->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContents);

        horizontalLayout->addWidget(typeEdit);

        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 85, 255);\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"padding:10px;\n"
"font: 300 9pt \"IRANYekan\";\n"
"border:1px solid black;\n"
"width:80px;\n"
"height:20px;"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        addbtn = new QPushButton(verticalLayoutWidget);
        addbtn->setObjectName("addbtn");
        addbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addbtn->setStyleSheet(QString::fromUtf8("background-color:lightgreen;\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"padding:5px;\n"
"font: 300 9pt \"IRANYekan\";\n"
"border:1px solid black;\n"
"width:240px;"));

        verticalLayout->addWidget(addbtn);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: #f77599;\n"
"border-radius:8px;"));
        tableWidget->setLocale(QLocale(QLocale::Persian, QLocale::Iran));

        verticalLayout->addWidget(tableWidget);

        label_3 = new QLabel(managemenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(560, 50, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rokh")});
        font.setPointSize(10);
        font.setWeight(QFont::Black);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 900 10pt \"Rokh\";"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        deletebtn = new QPushButton(managemenu);
        deletebtn->setObjectName("deletebtn");
        deletebtn->setGeometry(QRect(10, 390, 121, 38));
        deletebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deletebtn->setStyleSheet(QString::fromUtf8("background-color:red;\n"
"color: rgb(0, 0, 0);\n"
"border-radius:8px;\n"
"padding:5px;\n"
"font: 300 9pt \"IRANYekan\";\n"
"border:1px solid black;"));
        backbtn = new QPushButton(managemenu);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(10, 10, 31, 31));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(235, 87, 87);\n"
"border:0px;\n"
"padding:10px;\n"
"border-radius:8px;\n"
"\n"
"font: 800 9pt \"IRANYekan\";"));

        retranslateUi(managemenu);

        QMetaObject::connectSlotsByName(managemenu);
    } // setupUi

    void retranslateUi(QWidget *managemenu)
    {
        managemenu->setWindowTitle(QCoreApplication::translate("managemenu", "Manage Menu", nullptr));
        priceEdit->setPlaceholderText(QCoreApplication::translate("managemenu", "\331\202\333\214\331\205\330\252", nullptr));
        typeEdit->setItemText(0, QCoreApplication::translate("managemenu", "\331\201\330\263\330\252 \331\201\331\210\330\257", nullptr));
        typeEdit->setItemText(1, QCoreApplication::translate("managemenu", "\331\206\331\210\330\264\333\214\330\257\331\206\333\214", nullptr));
        typeEdit->setItemText(2, QCoreApplication::translate("managemenu", "\330\256\331\210\330\261\330\264\330\252", nullptr));
        typeEdit->setItemText(3, QCoreApplication::translate("managemenu", "\330\247\333\214\330\261\330\247\331\206\333\214 ", nullptr));
        typeEdit->setItemText(4, QCoreApplication::translate("managemenu", "\331\201\330\261\331\206\332\257\333\214", nullptr));
        typeEdit->setItemText(5, QCoreApplication::translate("managemenu", "\330\263\331\206\330\252\333\214", nullptr));
        typeEdit->setItemText(6, QCoreApplication::translate("managemenu", "\330\256\330\247\331\206\332\257\333\214 ", nullptr));

        typeEdit->setPlaceholderText(QCoreApplication::translate("managemenu", "\330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("managemenu", "\331\206\330\247\331\205 \330\272\330\260\330\247", nullptr));
        addbtn->setText(QCoreApplication::translate("managemenu", "\330\247\331\201\330\262\331\210\330\257\331\206 \330\272\330\260\330\247 \330\250\331\207 \331\205\331\206\331\210", nullptr));
        label_3->setText(QCoreApplication::translate("managemenu", "\330\252\330\272\333\214\333\214\330\261 \331\205\331\206\331\210", nullptr));
        deletebtn->setText(QCoreApplication::translate("managemenu", "\330\255\330\260\331\201 \330\272\330\260\330\247 \330\247\330\262 \331\205\331\206\331\210", nullptr));
        backbtn->setText(QCoreApplication::translate("managemenu", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class managemenu: public Ui_managemenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENU_H
