#include "cart.h"
#include "shoppage.h"
#include "ui_cart.h"

cart::cart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cart)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });
}

cart::~cart()
{
    delete ui;
}
