/********************************************************************************
** Form generated from reading UI file 'restaurantcard.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANTCARD_H
#define UI_RESTAURANTCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RestaurantCard
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labeltype;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *ratelabel;
    QWidget *widget;
    QWidget *widget_3;
    QWidget *widget_5;
    QWidget *widget_4;
    QWidget *widget_2;
    QPushButton *detailbtn;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelname;
    QFrame *frame_2;
    QLabel *labeladdress;
    QFrame *frame;

    void setupUi(QWidget *RestaurantCard)
    {
        if (RestaurantCard->objectName().isEmpty())
            RestaurantCard->setObjectName("RestaurantCard");
        RestaurantCard->resize(700, 250);
        horizontalLayoutWidget = new QWidget(RestaurantCard);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 701, 251));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labeltype = new QLabel(horizontalLayoutWidget);
        labeltype->setObjectName("labeltype");
        labeltype->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"color:rgba(200,200,200,200);\n"
"padding:5px;\n"
"background-color: rgb(0, 0, 127);\n"
""));

        verticalLayout->addWidget(labeltype);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ratelabel = new QHBoxLayout();
        ratelabel->setObjectName("ratelabel");
        widget = new QWidget(horizontalLayoutWidget);
        widget->setObjectName("widget");

        ratelabel->addWidget(widget);

        widget_3 = new QWidget(horizontalLayoutWidget);
        widget_3->setObjectName("widget_3");

        ratelabel->addWidget(widget_3);

        widget_5 = new QWidget(horizontalLayoutWidget);
        widget_5->setObjectName("widget_5");

        ratelabel->addWidget(widget_5);

        widget_4 = new QWidget(horizontalLayoutWidget);
        widget_4->setObjectName("widget_4");

        ratelabel->addWidget(widget_4);

        widget_2 = new QWidget(horizontalLayoutWidget);
        widget_2->setObjectName("widget_2");

        ratelabel->addWidget(widget_2);


        horizontalLayout_2->addLayout(ratelabel);


        verticalLayout->addLayout(horizontalLayout_2);

        detailbtn = new QPushButton(horizontalLayoutWidget);
        detailbtn->setObjectName("detailbtn");
        detailbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        detailbtn->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"color:black;\n"
"padding:5px;\n"
"background-color: rgb(255, 170, 255);\n"
"border:0px solid;\n"
"height:60px;"));

        verticalLayout->addWidget(detailbtn);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        labelname = new QLabel(horizontalLayoutWidget);
        labelname->setObjectName("labelname");
        labelname->setStyleSheet(QString::fromUtf8("font: 900 19pt \"Rokh\";\n"
"color:white;\n"
"padding:5px;\n"
"background-color: rgb(0, 0, 127);"));

        horizontalLayout_3->addWidget(labelname);

        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/plate.png);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout_3->addWidget(frame_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        labeladdress = new QLabel(horizontalLayoutWidget);
        labeladdress->setObjectName("labeladdress");
        labeladdress->setStyleSheet(QString::fromUtf8("font: 900 9pt \"Rokh\";\n"
"color:rgba(200,200,200,200);\n"
"padding:5px;\n"
"background-color: rgb(0, 0, 127);\n"
""));

        verticalLayout_3->addWidget(labeladdress);


        horizontalLayout->addLayout(verticalLayout_3);

        frame = new QFrame(RestaurantCard);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 701, 251));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"color:black;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->raise();
        horizontalLayoutWidget->raise();

        retranslateUi(RestaurantCard);

        QMetaObject::connectSlotsByName(RestaurantCard);
    } // setupUi

    void retranslateUi(QWidget *RestaurantCard)
    {
        RestaurantCard->setWindowTitle(QCoreApplication::translate("RestaurantCard", "Form", nullptr));
        labeltype->setText(QCoreApplication::translate("RestaurantCard", "\330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        detailbtn->setText(QCoreApplication::translate("RestaurantCard", "\330\257\333\214\330\257\331\206 \331\205\331\206\331\210\333\214 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        labelname->setText(QCoreApplication::translate("RestaurantCard", "\331\206\330\247\331\205 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        labeladdress->setText(QCoreApplication::translate("RestaurantCard", "\330\242\330\257\330\261\330\263 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestaurantCard: public Ui_RestaurantCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTCARD_H
