/********************************************************************************
** Form generated from reading UI file 'iutfood_firstpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IUTFOOD_FIRSTPAGE_H
#define UI_IUTFOOD_FIRSTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IUTFood
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *gotosignin;
    QPushButton *gotologin;
    QLabel *iutfood_label_forfirstpage;
    QLabel *iutfood_label_forfirstpage2;
    QFrame *frame;

    void setupUi(QMainWindow *IUTFood)
    {
        if (IUTFood->objectName().isEmpty())
            IUTFood->setObjectName("IUTFood");
        IUTFood->resize(800, 500);
        IUTFood->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(IUTFood);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(280, 290, 251, 104));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gotosignin = new QPushButton(verticalLayoutWidget);
        gotosignin->setObjectName("gotosignin");
        gotosignin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotosignin->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:black;\n"
"color:darkorange;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));

        verticalLayout->addWidget(gotosignin);

        gotologin = new QPushButton(verticalLayoutWidget);
        gotologin->setObjectName("gotologin");
        gotologin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        gotologin->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:darkorange;\n"
"color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;"));

        verticalLayout->addWidget(gotologin);

        iutfood_label_forfirstpage = new QLabel(centralwidget);
        iutfood_label_forfirstpage->setObjectName("iutfood_label_forfirstpage");
        iutfood_label_forfirstpage->setGeometry(QRect(300, 130, 221, 61));
        iutfood_label_forfirstpage->setStyleSheet(QString::fromUtf8("color:orange;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"text-align:center;"));
        iutfood_label_forfirstpage->setAlignment(Qt::AlignmentFlag::AlignCenter);
        iutfood_label_forfirstpage2 = new QLabel(centralwidget);
        iutfood_label_forfirstpage2->setObjectName("iutfood_label_forfirstpage2");
        iutfood_label_forfirstpage2->setGeometry(QRect(300, 190, 221, 81));
        iutfood_label_forfirstpage2->setStyleSheet(QString::fromUtf8("color:black;\n"
"font-family:Rokh;\n"
"border-radius:10px;\n"
"font-size:40px;\n"
"text-align:center;"));
        iutfood_label_forfirstpage2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-40, 0, 850, 501));
        frame->setStyleSheet(QString::fromUtf8("background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(25, 25, 255, 255));\n"
"\n"
"\n"
"border-image: url(:/new/images/bgfirstpage.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        IUTFood->setCentralWidget(centralwidget);
        frame->raise();
        verticalLayoutWidget->raise();
        iutfood_label_forfirstpage->raise();
        iutfood_label_forfirstpage2->raise();

        retranslateUi(IUTFood);

        QMetaObject::connectSlotsByName(IUTFood);
    } // setupUi

    void retranslateUi(QMainWindow *IUTFood)
    {
        IUTFood->setWindowTitle(QCoreApplication::translate("IUTFood", "IUTFood", nullptr));
        gotosignin->setText(QCoreApplication::translate("IUTFood", " ! \332\251\330\247\330\261\330\250\330\261 \330\254\330\257\333\214\330\257 \331\207\330\263\330\252\331\205 ", nullptr));
        gotologin->setText(QCoreApplication::translate("IUTFood", "\331\202\330\250\331\204\330\247 \330\253\330\250\330\252 \331\206\330\247\331\205 \332\251\330\261\330\257\331\205", nullptr));
        iutfood_label_forfirstpage->setText(QCoreApplication::translate("IUTFood", "IUT Food", nullptr));
        iutfood_label_forfirstpage2->setText(QCoreApplication::translate("IUTFood", "\330\242\333\214\331\210\330\252\333\214 \331\201\331\210\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IUTFood: public Ui_IUTFood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IUTFOOD_FIRSTPAGE_H
