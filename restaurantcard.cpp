#include "restaurantcard.h"
#include "ui_restaurantcard.h"

RestaurantCard::RestaurantCard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RestaurantCard)
{
    ui->setupUi(this);
}

RestaurantCard::~RestaurantCard()
{
    delete ui;
}

void RestaurantCard::setName(const QString &name)
{
    ui->labelname->setText(name);
}

void RestaurantCard::setAddress(const QString &address)
{
    ui->labeladdress->setText(address);
}

void RestaurantCard::setCategory(const QString &category)
{
    ui->labeltype->setText(category);
}

void RestaurantCard::setRating(int rating)
{
    // نمایشی ساده: تعداد ستاره‌های پر
    for (int i = 0; i < 5; ++i) {
        QWidget *star = ui->ratelabel->itemAt(i)->widget();
        if (star) {
            star->setStyleSheet(i < rating
                                    ? "background-color: gold; border-radius: 5px;"
                                    : "background-color: lightgray; border-radius: 5px;");
        }
    }
}
