#include "adminpage.h"
#include "iutfood_firstpage.h"
#include "restaurant.h"
#include "ui_adminpage.h"
#include "edituser.h"
#include "reports.h"

#include <QMessageBox>

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
    connect(ui->exitbtn, &QPushButton::clicked, this, [=]() {
        int confirm = QMessageBox::question(
            this,
            "خروج",
            "آیا مطمئن هستید که می‌خواهید خارج شوید؟",
            QMessageBox::Yes | QMessageBox::No
            );

        if (confirm == QMessageBox::Yes) {
            IUTFood *firstwin = new IUTFood();
            firstwin->setAttribute(Qt::WA_DeleteOnClose);
            firstwin->show();
            this->close();
        }
    });
}

Adminpage::~Adminpage()
{
    delete ui;
}
