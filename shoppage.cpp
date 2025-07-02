#include "shoppage.h"
#include "cart.h"
#include "history.h"
#include "panel.h"
#include "peygiri.h"
#include "ui_shoppage.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

#include "restaurantcard.h"  // کارت هر رستوران

ShopPage::ShopPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ShopPage)
{
    ui->setupUi(this);
    connect(ui->cartbtn, &QPushButton::clicked, this, [=]() {
        cart *cartwin = new cart();
        cartwin->setAttribute(Qt::WA_DeleteOnClose);
        cartwin->show();
        this->close();
    });
    connect(ui->panelbtn, &QPushButton::clicked, this, [=]() {
        panel *panelwin = new panel();
        panelwin->setAttribute(Qt::WA_DeleteOnClose);
        panelwin->show();
        this->close();
    });
    connect(ui->historybtn, &QPushButton::clicked, this, [=]() {
        history *historywin = new history();
        historywin->setAttribute(Qt::WA_DeleteOnClose);
        historywin->show();
        this->close();
    });
    connect(ui->orderbtn, &QPushButton::clicked, this, [=]() {
        peygiri *peygiriwin = new peygiri();
        peygiriwin->setAttribute(Qt::WA_DeleteOnClose);
        peygiriwin->show();
        this->close();
    });
    // تنظیم آیکون دکمه‌ها
    ui->panelbtn->setIcon(QIcon(":/new/images/usericon.svg"));
    ui->panelbtn->setIconSize(QSize(32, 32));
    ui->panelbtn->setText("");

    ui->historybtn->setIcon(QIcon(":/new/images/historyicon.png"));
    ui->historybtn->setIconSize(QSize(32, 32));
    ui->historybtn->setText("");

    ui->orderbtn->setIcon(QIcon(":/new/images/ordertrackingicon.png"));
    ui->orderbtn->setIconSize(QSize(32, 32));
    ui->orderbtn->setText("");

    ui->cartbtn->setIcon(QIcon(":/new/images/carticon.png"));
    ui->cartbtn->setIconSize(QSize(32, 32));
    ui->cartbtn->setText("");

    if (!ui->scrollAreaWidgetContents->layout()) {
        QVBoxLayout *mainLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);
        ui->scrollAreaWidgetContents->setLayout(mainLayout);
    }

    // اضافه کردن cardsContainer به layout
    if (ui->scrollAreaWidgetContents->layout()->indexOf(ui->cardsContainer) == -1) {
        ui->scrollAreaWidgetContents->layout()->addWidget(ui->cardsContainer);
    }

    // تنظیم درست برای expand شدن
    ui->cardsContainer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
    ui->scrollArea->setWidgetResizable(true);

    // بارگذاری کارت‌های رستوران
    loadRestaurants();
}

ShopPage::~ShopPage()
{
    delete ui;
}


void ShopPage::loadRestaurants()
{
    // اتصال به دیتابیس
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "RestaurantConnection");
    db.setDatabaseName("restaurant2.db");

    if (!db.open()) {
        qDebug() << "Database open error:" << db.lastError().text();
        QMessageBox::critical(this, "خطا", "اتصال به دیتابیس برقرار نشد.");
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT name, address, rate,status FROM restaurant")) {
        qDebug() << "Query error:" << query.lastError().text();
        QMessageBox::critical(this, "خطا", "خطا در خواندن اطلاعات رستوران‌ها");
        return;
    }
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->cardsContainer->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->cardsContainer);
        layout->setContentsMargins(10, 10, 10, 10);
        layout->setSpacing(15);
        ui->cardsContainer->setLayout(layout);
    }

    // حذف کارت‌های قبلی
    QLayoutItem *item;
    while ((item = layout->takeAt(0))) {
        if (QWidget *w = item->widget())
            w->deleteLater();
        delete item;
    }

    // افزودن کارت جدید
    while (query.next()) {
        QString name = query.value("name").toString();
        QString address = query.value("address").toString();
        int rating = query.value("rate").toInt();
        QString category = query.value("status").toString();

        RestaurantCard *card = new RestaurantCard();
        card->setFixedHeight(250);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setName(name);
        card->setAddress(address);
        card->setCategory(category);
        card->setRating(rating);

        layout->addWidget(card);
    }

    layout->addStretch();  // برای آخرین فاصله

    // اطمینان از آپدیت اسکرول
    ui->cardsContainer->adjustSize();
    ui->scrollAreaWidgetContents->adjustSize();




    db.close(); // دیتابیس رو ببند (اختیاری)
}

