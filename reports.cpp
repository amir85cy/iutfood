#include "reports.h"
#include "ui_reports.h"
#include "adminpage.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QDebug>

Reports::Reports(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reports)
{
    ui->setupUi(this);

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        Adminpage *adminWin = new Adminpage();
        adminWin->setAttribute(Qt::WA_DeleteOnClose);
        adminWin->show();
        this->close();
    });

    // استایل زیبا برای reportlist
    ui->reportlist->setStyleSheet(R"(
        QListWidget {
            border: 2px solid #aaaaaa;
            border-radius: 12px;
            border-image: url(:/new/images/listbg.jpg);
            font-family:iranyekan;
            padding: 30px;
        }

        QListWidget::item {
            background-color: #ffb48a;
            margin: 4px;
            padding: 8px;
            border-radius: 8px;
            color: #333;
        }

        QListWidget::item:selected {
            background-color: #3399ff;
            color: white;
        }

        QListWidget::item:hover {
            background-color: #3399ff;
            color: black;
        }
    )");

    // استایل زیبا برای orderlist
    ui->orderlist->setStyleSheet(R"(
        QListWidget {
            border: 2px solid #aaaaaa;
            border-radius: 12px;
            border-image: url(:/new/images/listbg.jpg);
            font-family:iranyekan;
            padding: 30px;
        }

        QListWidget::item {
            background-color: #ffb48a;
            padding: 0px;
            border-radius: 8px;
            color: #333;
        }

        QListWidget::item:selected {
            background-color: #3399ff;
            color: white;
        }

        QListWidget::item:hover {
            background-color: #3399ff;
            color: black;
        }
    )");

    loadOrdersFromDatabase();
}

Reports::~Reports()
{
    delete ui;
}

void Reports::loadOrdersFromDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "OrdersConnection");
    db.setDatabaseName("orders.db");

    if (!db.open()) {
        qDebug() << "Database Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT customer_username, restaurant_username, title, total_price FROM orders")) {
        qDebug() << "Query Error:" << query.lastError().text();
        db.close();
        return;
    }

    ui->reportlist->clear();
    ui->orderlist->clear();

    while (query.next()) {
        QString customer = query.value(0).toString();
        QString restaurant = query.value(1).toString();
        QString title = query.value(2).toString();
        int price = query.value(3).toInt();

        // آیتم کامل برای reportlist
        QString detailedText = QString("مشتری: %1\nرستوران: %2\nغذا: %3\nقیمت کل: %4 تومان")
                                   .arg(customer, restaurant, title, QString::number(price));

        QListWidgetItem* detailedItem = new QListWidgetItem(detailedText);
        detailedItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->reportlist->addItem(detailedItem);

        // آیتم خلاصه برای orderlist
        QString shortText = QString("%1 - %2").arg(title, restaurant);
        QListWidgetItem* summaryItem = new QListWidgetItem(shortText);
        summaryItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        ui->orderlist->addItem(summaryItem);
    }

    db.close();
}
