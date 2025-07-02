#include "peygiri.h"
#include "shoppage.h"
#include "ui_peygiri.h"

peygiri::peygiri(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::peygiri)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });
}

peygiri::~peygiri()
{
    delete ui;
}
