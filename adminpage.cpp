#include "adminpage.h"
#include "restaurant.h"
#include "ui_adminpage.h"
#include "edituser.h"
#include "reports.h"

Adminpage::Adminpage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Adminpage)
{
    ui->setupUi(this);
    connect(ui->gotoedituser, &QPushButton::clicked, this, [=]() {
        Edituser *edituserwin = new Edituser();
        edituserwin->setAttribute(Qt::WA_DeleteOnClose);
        edituserwin->show();
        this->close();
    });
    connect(ui->gotoreports, &QPushButton::clicked, this, [=]() {
        Reports *reportwin = new Reports();
        reportwin->setAttribute(Qt::WA_DeleteOnClose);
        reportwin->show();
        this->close();
    });
    connect(ui->gotorsts, &QPushButton::clicked, this, [=]() {
        restaurant *restaurantwin = new restaurant();
        restaurantwin->setAttribute(Qt::WA_DeleteOnClose);
        restaurantwin->show();
        this->close();
    });
}

Adminpage::~Adminpage()
{
    delete ui;
}
