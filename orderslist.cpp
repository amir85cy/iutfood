#include "orderslist.h"
#include "ui_orderslist.h"
#include "restaurateurpage.h"
#include <QTableWidgetItem>
#include <QTcpSocket>
#include <QDebug>

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

    // ستون‌ها
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "👤 مشتری" << "🍽 غذا" << "📦 وضعیت");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->tableWidget, &QTableWidget::cellClicked, this, [=](int row, int) {
        selectedRow = row;
    });

    // راه‌اندازی سرور
    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &orderslist::onNewConnection);

    if (!server->listen(QHostAddress::Any, 12345)) {
        qDebug() << "❌ Server failed to start!";
    } else {
        qDebug() << "✅ Server listening on port 12345";
    }

    // دکمه‌های تغییر وضعیت
    connect(ui->btnConfirm, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("📦 سفارش تأیید شد"));
            sendStatusToClient(selectedRow, "وضعیت سفارش شما: تأیید شد.");
        }
    });

    connect(ui->btnStartPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("🍳 در حال آماده‌سازی"));
            sendStatusToClient(selectedRow, "وضعیت سفارش شما: در حال آماده‌سازی.");
        }
    });

    connect(ui->btnPreparing, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("🍲 مرحله پخت"));
            sendStatusToClient(selectedRow, "وضعیت سفارش شما: در مرحله پخت است.");
        }
    });

    connect(ui->btnDelivered, &QPushButton::clicked, this, [=]() {
        if (selectedRow >= 0) {
            ui->tableWidget->setItem(selectedRow, 2, new QTableWidgetItem("✅ ارسال شد"));
            sendStatusToClient(selectedRow, "وضعیت سفارش شما: ارسال شد و در راه است.");
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
    if (parts.size() != 4) return;

    QString customer = parts[0];            // نام مشتری
    QString restUsername = parts[1];        // نام کاربری رستوران مقصد
    QString food = parts[2];                // نام غذا
    QString count = parts[3];               // تعداد

    QString currentRestUsername = "rest12"; // مقدار واقعی باید از دیتابیس یا لاگین بیاد

    if (restUsername != currentRestUsername)
        return;  // فقط سفارش‌های مربوط به رستوران فعلی را نمایش بده

    int newRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(newRow);

    QTableWidgetItem* customerItem = new QTableWidgetItem(customer);
    customerItem->setData(Qt::UserRole, QVariant::fromValue((void*)senderSocket));

    QTableWidgetItem* foodItem = new QTableWidgetItem(QString("%1 × %2").arg(food, count));
    QTableWidgetItem* statusItem = new QTableWidgetItem("⏳ در انتظار بررسی");

    ui->tableWidget->setItem(newRow, 0, customerItem);
    ui->tableWidget->setItem(newRow, 1, foodItem);
    ui->tableWidget->setItem(newRow, 2, statusItem);
}

void orderslist::sendStatusToClient(int row, const QString& message) {
    QTableWidgetItem* customerItem = ui->tableWidget->item(row, 0);
    if (!customerItem) return;

    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(customerItem->data(Qt::UserRole).value<void*>());
    if (socket && socket->state() == QTcpSocket::ConnectedState) {
        socket->write(message.toUtf8());
    }
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
