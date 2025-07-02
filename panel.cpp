#include "panel.h"
#include "shoppage.h"
#include "ui_panel.h"

panel::panel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::panel)
{
    ui->setupUi(this);
    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        ShopPage *shopwin = new ShopPage();
        shopwin->setAttribute(Qt::WA_DeleteOnClose);
        shopwin->show();
        this->close();
    });
}

panel::~panel()
{
    delete ui;
}
