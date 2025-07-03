/********************************************************************************
** Form generated from reading UI file 'restaurantpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANTPAGE_H
#define UI_RESTAURANTPAGE_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Restaurantpage
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *panelbtn;
    QPushButton *historybtn;
    QPushButton *cartbtn;
    QPushButton *orderbtn;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableView *foodstable;
    QTableView *commenttable;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addtocartbtn;
    QPushButton *likebtn;
    QPushButton *backbtn;
    QFrame *frame;

    void setupUi(QWidget *Restaurantpage)
    {
        if (Restaurantpage->objectName().isEmpty())
            Restaurantpage->setObjectName("Restaurantpage");
        Restaurantpage->resize(800, 500);
        Restaurantpage->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget_2 = new QWidget(Restaurantpage);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 92, 61));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color:orange;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:20px;\n"
"text-align:center;\n"
"padding:0px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:15px;\n"
"\n"
"padding:0px;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        gridLayoutWidget = new QWidget(Restaurantpage);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(720, 10, 71, 89));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        panelbtn = new QPushButton(gridLayoutWidget);
        panelbtn->setObjectName("panelbtn");
        panelbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        panelbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);\n"
"border:0px solid;\n"
"padding:0;\n"
"width:20px;\n"
"height:40px;\n"
"border-radius:7px;"));

        gridLayout->addWidget(panelbtn, 0, 0, 1, 1);

        historybtn = new QPushButton(gridLayoutWidget);
        historybtn->setObjectName("historybtn");
        historybtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        historybtn->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);\n"
"border:0px solid;\n"
"padding:0;\n"
"width:20px;\n"
"height:40px;\n"
"border-radius:7px;"));

        gridLayout->addWidget(historybtn, 1, 0, 1, 1);

        cartbtn = new QPushButton(gridLayoutWidget);
        cartbtn->setObjectName("cartbtn");
        cartbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cartbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);\n"
"border:0px solid;\n"
"padding:0;\n"
"width:20px;\n"
"height:40px;\n"
"border-radius:7px;"));

        gridLayout->addWidget(cartbtn, 0, 1, 1, 1);

        orderbtn = new QPushButton(gridLayoutWidget);
        orderbtn->setObjectName("orderbtn");
        orderbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        orderbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 208, 208);\n"
"border:0px solid;\n"
"padding:0;\n"
"width:20px;\n"
"height:40px;\n"
"border-radius:7px;"));

        gridLayout->addWidget(orderbtn, 1, 1, 1, 1);

        label_3 = new QLabel(Restaurantpage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 15, 351, 51));
        label_3->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"\n"
"padding:0px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalLayoutWidget = new QWidget(Restaurantpage);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 179, 781, 261));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        foodstable = new QTableView(horizontalLayoutWidget);
        foodstable->setObjectName("foodstable");
        foodstable->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        foodstable->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        foodstable->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";"));
        foodstable->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
        foodstable->setTextElideMode(Qt::TextElideMode::ElideLeft);

        horizontalLayout->addWidget(foodstable);

        commenttable = new QTableView(horizontalLayoutWidget);
        commenttable->setObjectName("commenttable");
        commenttable->setStyleSheet(QString::fromUtf8("font: 300 9pt \"IRANYekan\";"));

        horizontalLayout->addWidget(commenttable);

        horizontalLayoutWidget_2 = new QWidget(Restaurantpage);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(9, 110, 781, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:iranyekan;\n"
"border-radius:10px;\n"
"\n"
"\n"
"padding:0px;\n"
"font: 900 30px \"IRANYekan\";"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_5);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:iranyekan;\n"
"border-radius:10px;\n"
"\n"
"\n"
"padding:0px;\n"
"font: 900 30px \"IRANYekan\";"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalLayoutWidget_3 = new QWidget(Restaurantpage);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 450, 781, 42));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        addtocartbtn = new QPushButton(horizontalLayoutWidget_3);
        addtocartbtn->setObjectName("addtocartbtn");
        addtocartbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addtocartbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 127);\n"
"border:0px;\n"
"color:black;\n"
"padding:5px;\n"
"\n"
"font: 700 9pt \"IRANYekan\";"));

        horizontalLayout_3->addWidget(addtocartbtn);

        likebtn = new QPushButton(horizontalLayoutWidget_3);
        likebtn->setObjectName("likebtn");
        likebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        likebtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 127);\n"
"border:0px;\n"
"color:black;\n"
"padding:5px;\n"
"\n"
"font: 700 9pt \"IRANYekan\";"));

        horizontalLayout_3->addWidget(likebtn);

        backbtn = new QPushButton(Restaurantpage);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(10, 80, 201, 29));
        backbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        backbtn->setStyleSheet(QString::fromUtf8("padding:2px;\n"
"\n"
"background-color: rgb(255, 39, 79);\n"
"border:0px solid;\n"
"color:black;\n"
"font: 900 9pt \"IRANYekanFN\";\n"
"border-radius:5px;"));
        frame = new QFrame(Restaurantpage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 800, 500));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 255);\n"
"\n"
"border-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->raise();
        verticalLayoutWidget_2->raise();
        gridLayoutWidget->raise();
        label_3->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_2->raise();
        horizontalLayoutWidget_3->raise();
        backbtn->raise();

        retranslateUi(Restaurantpage);

        QMetaObject::connectSlotsByName(Restaurantpage);
    } // setupUi

    void retranslateUi(QWidget *Restaurantpage)
    {
        Restaurantpage->setWindowTitle(QCoreApplication::translate("Restaurantpage", "Form", nullptr));
        label->setText(QCoreApplication::translate("Restaurantpage", "IUT Food", nullptr));
        label_2->setText(QCoreApplication::translate("Restaurantpage", "\330\242\333\214\331\210\330\252\333\214 \331\201\331\210\330\257", nullptr));
        panelbtn->setText(QCoreApplication::translate("Restaurantpage", ".", nullptr));
        historybtn->setText(QCoreApplication::translate("Restaurantpage", "PushButton", nullptr));
        cartbtn->setText(QCoreApplication::translate("Restaurantpage", "PushButton", nullptr));
        orderbtn->setText(QCoreApplication::translate("Restaurantpage", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("Restaurantpage", "\331\206\330\247\331\205 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        label_5->setText(QCoreApplication::translate("Restaurantpage", "\331\205\331\206\331\210\333\214 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        label_4->setText(QCoreApplication::translate("Restaurantpage", "\331\206\330\270\330\261\330\247\330\252 ", nullptr));
        addtocartbtn->setText(QCoreApplication::translate("Restaurantpage", "\330\247\331\201\330\262\331\210\330\257\331\206 \330\250\331\207 \330\263\330\250\330\257 \330\256\330\261\333\214\330\257", nullptr));
        likebtn->setText(QCoreApplication::translate("Restaurantpage", "\331\204\330\247\333\214\332\251 \332\251\330\261\330\257\331\206 \330\247\333\214\331\206 \332\251\330\247\331\205\331\206\330\252\342\235\244\357\270\217", nullptr));
        backbtn->setText(QCoreApplication::translate("Restaurantpage", "\330\250\330\247\330\262\332\257\330\264\330\252 \330\250\331\207 \331\204\333\214\330\263\330\252 \330\261\330\263\330\252\331\210\330\261\330\247\331\206 \331\207\330\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Restaurantpage: public Ui_Restaurantpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTPAGE_H
