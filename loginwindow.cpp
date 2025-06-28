#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "iutfood_firstpage.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        IUTFood *firstwin = new IUTFood();
        firstwin->setAttribute(Qt::WA_DeleteOnClose);
        firstwin->show();
        this->close();
    });
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
