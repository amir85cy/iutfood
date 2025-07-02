#include "orderslist.h"
#include "ui_orderslist.h"
#include "restaurateurpage.h"

orderslist::orderslist(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::orderslist)
{
    ui->setupUi(this);
    ui->tableWidget->setStyleSheet(R"(
    QHeaderView::section {
        background-color: #f0f0f0;
        border-bottom: 1px solid #aaaaaa;
        padding: 6px;
        font-weight: bold;
        color:black;
        font-family:iranyekan;
    }
    QTableWidget {
        gridline-color: #aaaaaa;
        border: 1px solid #aaaaaa;
        font-family:iranyekan;
    }
    QTableWidget::item:selected {
        background-color: #0066cc;
        color: white;
    }

    )");

    connect(ui->backbtn, &QPushButton::clicked, this, [=]() {
        Restaurateurpage *rsrtwin = new Restaurateurpage();
        rsrtwin->setAttribute(Qt::WA_DeleteOnClose);
        rsrtwin->show();
        this->close();
    });

    // تنظیم ستون‌های جدول
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "👤 مشتری" << "🍽 غذا" << "📦 وضعیت");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


    connect(ui->tableWidget, &QTableWidget::cellClicked, this, [=](int row, int) {
        selectedRow = row;
    });

    // سرور
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &orderslist::onNewConnection);

    if (!server->listen(QHostAddress::Any, 12345)) {
        qDebug() << "❌ Server failed to start!";
    } else {
        qDebug() << "✅ Server listening on port 12345";
    }

    connect(ui->btnConfirm, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("📦 سفارش تأیید شد"));
            QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(ui->tableWidget->item(selectedRow, 0)->data(Qt::UserRole).value<void*>());
            if (socket && socket->state() == QTcpSocket::ConnectedState) {
                socket->write(QString("وضعیت سفارش شما: تأیید شد.").toUtf8());
            }
        }
    });

    connect(ui->btnStartPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("🍳 در حال آماده‌سازی"));
            QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(ui->tableWidget->item(selectedRow, 0)->data(Qt::UserRole).value<void*>());
            if (socket && socket->state() == QTcpSocket::ConnectedState) {
                socket->write(QString("وضعیت سفارش شما: در حال آماده‌سازی.").toUtf8());
            }
        }
    });

    connect(ui->btnPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("🍲 مرحله پخت"));
            QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(ui->tableWidget->item(selectedRow, 0)->data(Qt::UserRole).value<void*>());
            if (socket && socket->state() == QTcpSocket::ConnectedState) {
                socket->write(QString("وضعیت سفارش شما: در مرحله پخت است.").toUtf8());
            }
        }
    });

    connect(ui->btnDelivered, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("✅ ارسال شد"));
            QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(ui->tableWidget->item(selectedRow, 0)->data(Qt::UserRole).value<void*>());
            if (socket && socket->state() == QTcpSocket::ConnectedState) {
                socket->write(QString("وضعیت سفارش شما: ارسال شد و در راه است.").toUtf8());
            }
        }
    });
}

void orderslist::onNewConnection() {
    QTcpSocket* newClientSocket = server->nextPendingConnection();
    clientSockets.append(newClientSocket);
    connect(newClientSocket, &QTcpSocket::readyRead, this, &orderslist::onReadyRead);
    connect(newClientSocket, &QTcpSocket::disconnected, this, &orderslist::onClientDisconnected);
    qDebug() << "🔗 مشتری جدید وصل شد. تعداد مشتریان متصل: " << clientSockets.size();
}

void orderslist::onReadyRead() {
    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (!senderSocket) return;

    QByteArray data = senderSocket->readAll();
    QString text = QString::fromUtf8(data).trimmed();
    qDebug() << "📥 سفارش جدید: " << text;

    QStringList parts = text.split(":");
    if (parts.size() != 2) return;

    QString customer = parts[0];
    QString food = parts[1];

    int newRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(newRow);

    QTableWidgetItem* customerItem = new QTableWidgetItem(customer);
    customerItem->setData(Qt::UserRole, QVariant::fromValue((void*)senderSocket));
    QTableWidgetItem* foodItem = new QTableWidgetItem(food);
    QTableWidgetItem* statusItem = new QTableWidgetItem("⏳ در انتظار بررسی");

    ui->tableWidget->setItem(newRow, 0, customerItem);
    ui->tableWidget->setItem(newRow, 1, foodItem);
    ui->tableWidget->setItem(newRow, 2, statusItem);
}

void orderslist::onClientDisconnected() {
    QTcpSocket* senderSocket = qobject_cast<QTcpSocket*>(sender());
    if (senderSocket) {
        clientSockets.removeOne(senderSocket);
        senderSocket->deleteLater();
        qDebug() << "❌ مشتری قطع شد. تعداد فعلی: " << clientSockets.size();
    }
}

orderslist::~orderslist() {
    delete ui;
}
