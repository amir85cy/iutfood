/********************************************************************************
** Form generated from reading UI file 'shoppage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPAGE_H
#define UI_SHOPPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShopPage
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *cardsContainer;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
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
    QFrame *frame;
    QPushButton *exitbtn;

    void setupUi(QWidget *ShopPage)
    {
        if (ShopPage->objectName().isEmpty())
            ShopPage->setObjectName("ShopPage");
        ShopPage->resize(800, 500);
        ShopPage->setMinimumSize(QSize(800, 500));
        ShopPage->setMaximumSize(QSize(800, 500));
        ShopPage->setStyleSheet(QString::fromUtf8(""));
        scrollArea = new QScrollArea(ShopPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 110, 780, 381));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 778, 379));
        cardsContainer = new QWidget(scrollAreaWidgetContents);
        cardsContainer->setObjectName("cardsContainer");
        cardsContainer->setGeometry(QRect(9, 19, 751, 351));
        verticalLayoutWidget = new QWidget(cardsContainer);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, -1, 741, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget_2 = new QWidget(ShopPage);
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

        gridLayoutWidget = new QWidget(ShopPage);
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

        label_3 = new QLabel(ShopPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 15, 351, 51));
        label_3->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"\n"
"padding:0px;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(ShopPage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 801, 501));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        exitbtn = new QPushButton(frame);
        exitbtn->setObjectName("exitbtn");
        exitbtn->setGeometry(QRect(10, 80, 201, 29));
        exitbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitbtn->setStyleSheet(QString::fromUtf8("padding:2px;\n"
"\n"
"background-color: rgb(255, 39, 79);\n"
"border:0px solid;\n"
"color:black;\n"
"font: 900 9pt \"IRANYekanFN\";\n"
"border-radius:5px;"));
        frame->raise();
        scrollArea->raise();
        verticalLayoutWidget_2->raise();
        gridLayoutWidget->raise();
        label_3->raise();

        retranslateUi(ShopPage);

        QMetaObject::connectSlotsByName(ShopPage);
    } // setupUi

    void retranslateUi(QWidget *ShopPage)
    {
        ShopPage->setWindowTitle(QCoreApplication::translate("ShopPage", "Form", nullptr));
        label->setText(QCoreApplication::translate("ShopPage", "IUT Food", nullptr));
        label_2->setText(QCoreApplication::translate("ShopPage", "\330\242\333\214\331\210\330\252\333\214 \331\201\331\210\330\257", nullptr));
        panelbtn->setText(QCoreApplication::translate("ShopPage", ".", nullptr));
        historybtn->setText(QCoreApplication::translate("ShopPage", "PushButton", nullptr));
        cartbtn->setText(QCoreApplication::translate("ShopPage", "PushButton", nullptr));
        orderbtn->setText(QCoreApplication::translate("ShopPage", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("ShopPage", "\331\204\333\214\330\263\330\252 \330\261\330\263\330\252\331\210\330\261\330\247\331\206 \331\207\330\247", nullptr));
        exitbtn->setText(QCoreApplication::translate("ShopPage", "\330\256\330\261\331\210\330\254 \330\247\330\262 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShopPage: public Ui_ShopPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPAGE_H
