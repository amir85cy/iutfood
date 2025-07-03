#include "orderslist.h"
#include "global.h"
#include "ui_orderslist.h"
#include "restaurateurpage.h"
#include <QTableWidgetItem>
#include <QDebug>
#include <QDataStream>

orderslist::orderslist(QWidget *parent)
    : QWidget(parent), ui(new Ui::orderslist) {
    ui->setupUi(this);
    ui->tableWidget->setStyleSheet(R"(
    QHeaderView::section {
        background-color: #f0f0f0;
        border-bottom: 1px solid #aaaaaa;
        padding: 6px;
        font-weight: bold;
        color: black;
        font-family: iranyekan;
    }
    QTableWidget {
        gridline-color: #aaaaaa;
        border: 1px solid #aaaaaa;
        font-family: iranyekan;
    }
    QTableWidget::item:selected {
        background-color: #0066cc;
        color: white;
    }
)");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(
        { "👤 مشتری", "🍽 غذا", "📦 وضعیت", "🔢 کد سفارش" });
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        auto *win = new Restaurateurpage();
        win->setAttribute(Qt::WA_DeleteOnClose);
        win->show();
        this->close();
    });

    connect(ui->btnConfirm, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) sendStatusToClient(selectedRow, "سفارش تأیید شد");
    });
    connect(ui->btnStartPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) sendStatusToClient(selectedRow, "در حال آماده‌سازی");
    });
    connect(ui->btnPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) sendStatusToClient(selectedRow, "مرحله پخت");
    });
    connect(ui->btnDelivered, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) sendStatusToClient(selectedRow, "ارسال شد و در راه است");
    });

    connect(ui->tableWidget, &QTableWidget::cellClicked, this, [&](int row, int) {
        selectedRow = row;
    });

    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &orderslist::onNewConnection);
    if (!server->listen(QHostAddress::Any, 12345)) {
        qDebug() << "[Server] failed to start on port 12345";
    } else {
        qDebug() << "[Server] listening on 12345";
    }
}

void orderslist::onNewConnection() {
    auto *sock = server->nextPendingConnection();
    clientSockets.append(sock);
    connect(sock, &QTcpSocket::readyRead, this, &orderslist::onReadyRead);
    connect(sock, &QTcpSocket::disconnected, this, &orderslist::onClientDisconnected);
    qDebug() << "[Server] client connected, total:" << clientSockets.size();
}

void orderslist::onReadyRead() {
    auto *sock = qobject_cast<QTcpSocket*>(sender());
    if (!sock) return;

    QByteArray data = sock->readAll();
    QString text = QString::fromUtf8(data).trimmed();
    qDebug() << "[Server] order in:" << text;

    QStringList parts = text.split(":");
    if (parts.size() != 5) return;

    QString clientUsername = parts[0];
    QString restUsername   = parts[1];
    QString foodName       = parts[2];
    int count              = parts[3].toInt();
    int num                = parts[4].toInt();

    if (restUsername != loggedInUsername)
        return;

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    auto *itemCustomer = new QTableWidgetItem(clientUsername);
    itemCustomer->setData(Qt::UserRole, QVariant::fromValue((void*)sock));
    ui->tableWidget->setItem(row, 0, itemCustomer);


    QString foodCount = QString("%1 × %2").arg(count).arg(foodName);
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(foodCount));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem("⏳ در انتظار بررسی"));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(num)));
}


void orderslist::sendStatusToClient(int row, const QString &status) {
    auto *itemCustomer = ui->tableWidget->item(row, 0);
    auto *itemCode = ui->tableWidget->item(row, 3);
    if (!itemCustomer || !itemCode) return;

    auto *sock = reinterpret_cast<QTcpSocket*>(itemCustomer->data(Qt::UserRole).value<void*>());
    if (!sock || sock->state() != QAbstractSocket::ConnectedState) return;

    QString msg = QString("%1:%2:%3:%4")
                      .arg(loggedInUsername, itemCustomer->text(),
                           itemCode->text(), status);
    sock->write(msg.toUtf8());
    sock->flush();
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem("📦 " + status));
    qDebug() << "[Server] sent status:" << msg;
}

void orderslist::onClientDisconnected() {
    auto *sock = qobject_cast<QTcpSocket*>(sender());
    if (!sock) return;
    clientSockets.removeOne(sock);
    sock->deleteLater();
    qDebug() << "[Server] client disconnected, remaining:" << clientSockets.size();
}

orderslist::~orderslist() {
    delete ui;
}
