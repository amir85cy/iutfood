#include "restaurateurpage.h"
#include "ui_restaurateurpage.h"
#include "orderslist.h"
#include "managemenu.h"
#include "iutfood_firstpage.h"
#include <QMessageBox>

Restaurateurpage::Restaurateurpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Restaurateurpage)
{
    ui->setupUi(this);

    connect(ui->gotoorders, &QPushButton::clicked, this, [=]() {
        orderslist *orderwin = new orderslist();
        orderwin->setAttribute(Qt::WA_DeleteOnClose);
        orderwin->show();
        this->close();
    });

    connect(ui->gotoeditmenu, &QPushButton::clicked, this, [=]() {
        managemenu *editmenuwin = new managemenu();
        editmenuwin->setAttribute(Qt::WA_DeleteOnClose);
        editmenuwin->show();
        this->close();
    });

    connect(ui->exitbtn, &QPushButton::clicked, this, [=]() {
        int confirm = QMessageBox::question(
            this,
            "خروج",
            "آیا مطمئن هستید که می‌خواهید خارج شوید؟",
            QMessageBox::Yes | QMessageBox::No);

        if (confirm == QMessageBox::Yes) {
            IUTFood *firstwin = new IUTFood();
            firstwin->setAttribute(Qt::WA_DeleteOnClose);
            firstwin->show();
            this->close();
        }
    });
}

Restaurateurpage::~Restaurateurpage()
{
    delete ui;
}
