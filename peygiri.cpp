#include "peygiri.h"
#include "ui_peygiri.h"
#include "global.h"
#include <QTableWidgetItem>
#include <QDebug>

peygiri::peygiri(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::peygiri)
{
    ui->setupUi(this);

    // تنظیم جدول با 3 ستون
    ui->statusTable->setColumnCount(3);
    ui->statusTable->setHorizontalHeaderLabels({"نام رستوران", "کد سفارش", "وضعیت سفارش"});
    ui->statusTable->horizontalHeader()->setStretchLastSection(true);
    ui->statusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    socket = globalSocket;

    connect(socket, &QTcpSocket::readyRead, this, &peygiri::onReadyRead);
}

peygiri::~peygiri() {
    delete ui;
}

void peygiri::onReadyRead() {
    QByteArray data = socket->readAll();
    QString msg = QString::fromUtf8(data).trimmed();
    QStringList parts = msg.split(":");
    if (parts.size() < 4) return;

    QString restaurantUsername = parts[0];
    QString customerUsername = parts[1];
    QString orderCode = parts[2];
    QString status = parts[3];

    if (customerUsername != loggedInUsername)
        return;

    int row = ui->statusTable->rowCount();
    ui->statusTable->insertRow(row);

    ui->statusTable->setItem(row, 0, new QTableWidgetItem(restaurantUsername));
    ui->statusTable->setItem(row, 1, new QTableWidgetItem(orderCode));
    ui->statusTable->setItem(row, 2, new QTableWidgetItem(status));

    ui->statusTable->resizeColumnsToContents();
    ui->statusTable->horizontalHeader()->setStretchLastSection(true);
}
