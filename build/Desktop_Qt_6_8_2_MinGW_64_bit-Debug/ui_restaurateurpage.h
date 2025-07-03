/********************************************************************************
** Form generated from reading UI file 'restaurateurpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURATEURPAGE_H
#define UI_RESTAURATEURPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Restaurateurpage
{
public:
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *gotoeditmenu;
    QPushButton *gotoorders;
    QFrame *frame;
    QPushButton *exitbtn;

    void setupUi(QWidget *Restaurateurpage)
    {
        if (Restaurateurpage->objectName().isEmpty())
            Restaurateurpage->setObjectName("Restaurateurpage");
        Restaurateurpage->resize(800, 500);
        label_2 = new QLabel(Restaurateurpage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 100, 531, 101));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(33, 33, 33);\n"
"font-family:Rokh;\n"
"border-radius:50px;\n"
"font-size:40px;\n"
"text-align:center;\n"
"background-color:#e6d8bf;"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(Restaurateurpage);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(320, 240, 160, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gotoeditmenu = new QPushButton(verticalLayoutWidget);
        gotoeditmenu->setObjectName("gotoeditmenu");
        gotoeditmenu->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotoeditmenu->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"border:1px solid black;\n"
"background-color: rgb(0, 170, 255);\n"
"color:black;\n"
"font: 900 9pt \"Rokh\";\n"
"border-radius:10px;\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #007991, stop:1 #78ffd6);"));

        verticalLayout->addWidget(gotoeditmenu);

        gotoorders = new QPushButton(verticalLayoutWidget);
        gotoorders->setObjectName("gotoorders");
        gotoorders->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotoorders->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"border:1px solid black;\n"
"background-color: rgb(255, 170, 255);\n"
"color:black;\n"
"font: 900 9pt \"Rokh\";\n"
"border-radius:10px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #f4c4f3, stop:1 #fc67fa);\n"
"\n"
"\n"
""));

        verticalLayout->addWidget(gotoorders);

        frame = new QFrame(Restaurateurpage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 801, 501));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/Restaurateurpagebg.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        exitbtn = new QPushButton(Restaurateurpage);
        exitbtn->setObjectName("exitbtn");
        exitbtn->setGeometry(QRect(630, 10, 158, 41));
        exitbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitbtn->setStyleSheet(QString::fromUtf8("padding:5px;\n"
"border:5px solid red;\n"
"background-color: rgb(255, 170, 255);\n"
"color:black;\n"
"font: 900 8pt \"Rokh\";\n"
"border-radius:15px;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #cb2d3e, stop:1 #ef473a);\n"
"\n"
"\n"
""));
        frame->raise();
        label_2->raise();
        verticalLayoutWidget->raise();
        exitbtn->raise();

        retranslateUi(Restaurateurpage);

        QMetaObject::connectSlotsByName(Restaurateurpage);
    } // setupUi

    void retranslateUi(QWidget *Restaurateurpage)
    {
        Restaurateurpage->setWindowTitle(QCoreApplication::translate("Restaurateurpage", "Restauranteur", nullptr));
        label_2->setText(QCoreApplication::translate("Restaurateurpage", "\330\261\330\263\330\252\331\210\330\261\330\247\331\206\330\257\330\247\330\261 \330\271\330\262\333\214\330\262 \330\256\331\210\330\264 \330\242\331\205\330\257\333\214\330\257", nullptr));
        gotoeditmenu->setText(QCoreApplication::translate("Restaurateurpage", "\330\252\330\272\333\214\333\214\330\261 \331\205\331\206\331\210 ", nullptr));
        gotoorders->setText(QCoreApplication::translate("Restaurateurpage", "\330\263\331\201\330\247\330\261\330\264\330\247\330\252 ", nullptr));
        exitbtn->setText(QCoreApplication::translate("Restaurateurpage", "\330\256\330\261\331\210\330\254 \330\247\330\262 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Restaurateurpage: public Ui_Restaurateurpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURATEURPAGE_H
