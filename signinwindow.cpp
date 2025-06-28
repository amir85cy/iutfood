#include "signinwindow.h"
#include "ui_signinwindow.h"
#include "iutfood_firstpage.h"

Signinwindow::Signinwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Signinwindow)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });
}

Signinwindow::~Signinwindow()
{
    delete ui;
}
