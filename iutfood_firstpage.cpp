#include "iutfood_firstpage.h"
#include "ui_iutfood_firstpage.h"
#include "loginwindow.h"
#include "signinwindow.h"

IUTFood::IUTFood(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IUTFood)
{
    ui->setupUi(this);
    connect(ui->gotologin, &QPushButton::clicked, this, [=]() {
        LoginWindow *loginWin = new LoginWindow();
        loginWin->setAttribute(Qt::WA_DeleteOnClose);
        loginWin->show();
        this->close();
    });
    connect(ui->gotosignin, &QPushButton::clicked, this, [=]() {
        Signinwindow *signwin = new Signinwindow();
        signwin->setAttribute(Qt::WA_DeleteOnClose);
        signwin->show();
        this->close();
    });
}

IUTFood::~IUTFood()
{
    delete ui;
}
