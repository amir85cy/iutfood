/********************************************************************************
** Form generated from reading UI file 'edituser.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSER_H
#define UI_EDITUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Edituser
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *deletebtn;
    QPushButton *blockbtn;
    QPushButton *viewbtn;
    QPushButton *editrolebtn;
    QListWidget *listWidget;
    QPushButton *backbtn;

    void setupUi(QMainWindow *Edituser)
    {
        if (Edituser->objectName().isEmpty())
            Edituser->setObjectName("Edituser");
        Edituser->resize(800, 500);
        Edituser->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Edituser);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(510, -10, 201, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Morabba")});
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 20pt \"Morabba\";"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -10, 811, 511));
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/edituserbg.png);\n"
"\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(240, 80, 211, 225));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        deletebtn = new QPushButton(verticalLayoutWidget);
        deletebtn->setObjectName("deletebtn");
        deletebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deletebtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ef3b36, stop:1 #ffffff);\n"
"color: rgb(0, 0, 0);\n"
"padding:10px;\n"
"font: 9pt \"Rokh\";\n"
"border:0px solid;\n"
"border-radius:10px"));

        verticalLayout->addWidget(deletebtn);

        blockbtn = new QPushButton(verticalLayoutWidget);
        blockbtn->setObjectName("blockbtn");
        blockbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        blockbtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ef3b36, stop:1 #ffffff);\n"
"color: rgb(0, 0, 0);\n"
"padding:10px;\n"
"font: 9pt \"Rokh\";\n"
"border:0px solid;\n"
"border-radius:10px"));

        verticalLayout->addWidget(blockbtn);

        viewbtn = new QPushButton(verticalLayoutWidget);
        viewbtn->setObjectName("viewbtn");
        viewbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        viewbtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ef3b36, stop:1 #ffffff);\n"
"color: rgb(0, 0, 0);\n"
"padding:10px;\n"
"font: 9pt \"Rokh\";\n"
"border:0px solid;\n"
"border-radius:10px"));

        verticalLayout->addWidget(viewbtn);

        editrolebtn = new QPushButton(verticalLayoutWidget);
        editrolebtn->setObjectName("editrolebtn");
        editrolebtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        editrolebtn->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ef3b36, stop:1 #ffffff);\n"
"color: rgb(0, 0, 0);\n"
"padding:10px;\n"
"font: 9pt \"Rokh\";\n"
"border:0px solid;\n"
"border-radius:10px"));

        verticalLayout->addWidget(editrolebtn);

        listWidget = new QListWidget(centralwidget);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::UserAvailable));
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem1->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem2->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem3->setIcon(icon);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qlistwidgetitem4->setIcon(icon);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(470, 60, 281, 411));
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        listWidget->setStyleSheet(QString::fromUtf8("border-image: url(:/new/images/listbg.jpg);\n"
"\n"
"border-radius:10px;"));
        backbtn = new QPushButton(centralwidget);
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
        Edituser->setCentralWidget(centralwidget);
        frame->raise();
        label->raise();
        verticalLayoutWidget->raise();
        listWidget->raise();
        backbtn->raise();

        retranslateUi(Edituser);

        QMetaObject::connectSlotsByName(Edituser);
    } // setupUi

    void retranslateUi(QMainWindow *Edituser)
    {
        Edituser->setWindowTitle(QCoreApplication::translate("Edituser", "Edit User", nullptr));
        label->setText(QCoreApplication::translate("Edituser", "\331\204\333\214\330\263\330\252 \332\251\330\247\330\261\330\250\330\261\330\247\331\206", nullptr));
        deletebtn->setText(QCoreApplication::translate("Edituser", "\330\255\330\260\331\201 \332\251\330\247\330\261\330\250\330\261", nullptr));
        blockbtn->setText(QCoreApplication::translate("Edituser", "\330\250\331\204\330\247\332\251/\330\242\331\206\330\250\331\204\330\247\332\251 \332\251\330\261\330\257\331\206 \332\251\330\247\330\261\330\250\330\261", nullptr));
        viewbtn->setText(QCoreApplication::translate("Edituser", "\331\205\330\264\330\247\331\207\330\257\331\207 \332\251\330\247\330\261\330\250\330\261", nullptr));
        editrolebtn->setText(QCoreApplication::translate("Edituser", "\330\252\330\272\333\214\333\214\330\261 \331\206\331\202\330\264 \330\250\331\207 \330\247\330\257\331\205\333\214\331\206", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Edituser", "\330\250\333\214\330\252\330\247", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Edituser", "\330\271\331\204\333\214", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Edituser", "\331\201\330\247\330\267\331\205\331\207", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Edituser", "\330\247\331\205\333\214\330\261\330\261\330\266\330\247", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Edituser", "\330\247\331\205\333\214\330\261\330\255\330\263\333\214\331\206", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        backbtn->setText(QCoreApplication::translate("Edituser", "<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Edituser: public Ui_Edituser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSER_H
