/********************************************************************************
** Form generated from reading UI file 'restaurant.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANT_H
#define UI_RESTAURANT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restaurant
{
public:
    QListWidget *listWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *onactivebtn;
    QPushButton *activebtn;
    QFrame *frame;
    QLabel *label;
    QPushButton *backbtn;

    void setupUi(QWidget *restaurant)
    {
        if (restaurant->objectName().isEmpty())
            restaurant->setObjectName("restaurant");
        restaurant->resize(800, 500);
        restaurant->setMinimumSize(QSize(800, 500));
        restaurant->setMaximumSize(QSize(800, 500));
        restaurant->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        listWidget = new QListWidget(restaurant);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(50, 90, 300, 400));
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        listWidget->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #6190e8, stop:1 #a7bfe8);\n"
"border:10px;\n"
"border-radius:10px"));
        listWidget->setLocale(QLocale(QLocale::Persian, QLocale::Iran));
        listWidget->setTextElideMode(Qt::TextElideMode::ElideRight);
        horizontalLayoutWidget = new QWidget(restaurant);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(440, 20, 317, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        onactivebtn = new QPushButton(horizontalLayoutWidget);
        onactivebtn->setObjectName("onactivebtn");
        onactivebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        onactivebtn->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(235, 87, 87);\n"
"border:0px;\n"
"padding:10px;\n"
"border-radius:8px;\n"
"\n"
"font: 300 9pt \"iranyekan\";"));

        horizontalLayout->addWidget(onactivebtn);

        activebtn = new QPushButton(horizontalLayoutWidget);
        activebtn->setObjectName("activebtn");
        activebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        activebtn->setStyleSheet(QString::fromUtf8("background-color: rgb(69, 182, 73);\n"
"color: rgb(0, 0, 0);\n"
"border:0px;\n"
"padding:10px;\n"
"border-radius:8px;\n"
"font: 300 9pt \"iranyekan\";"));

        horizontalLayout->addWidget(activebtn);

        frame = new QFrame(restaurant);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-11, -11, 811, 511));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/restaurantbg.png);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 30, 231, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Rokh")});
        font.setPointSize(15);
        font.setWeight(QFont::Black);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 900 15pt \"Rokh\";\n"
"\n"
"color: rgb(0, 0, 0);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backbtn = new QPushButton(restaurant);
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
        frame->raise();
        listWidget->raise();
        horizontalLayoutWidget->raise();
        backbtn->raise();

        retranslateUi(restaurant);

        QMetaObject::connectSlotsByName(restaurant);
    } // setupUi

    void retranslateUi(QWidget *restaurant)
    {
        restaurant->setWindowTitle(QCoreApplication::translate("restaurant", "Restaurants", nullptr));
        onactivebtn->setText(QCoreApplication::translate("restaurant", "\330\272\333\214\330\261\331\201\330\271\330\247\331\204 \332\251\330\261\330\257\331\206 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        activebtn->setText(QCoreApplication::translate("restaurant", "\331\201\330\271\330\247\331\204 \332\251\330\261\330\257\331\206 \330\261\330\263\330\252\331\210\330\261\330\247\331\206", nullptr));
        label->setText(QCoreApplication::translate("restaurant", "\331\204\333\214\330\263\330\252 \330\261\330\263\330\252\331\210\330\261\330\247\331\206 \331\207\330\247", nullptr));
        backbtn->setText(QCoreApplication::translate("restaurant", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class restaurant: public Ui_restaurant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANT_H
