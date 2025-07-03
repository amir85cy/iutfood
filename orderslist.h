#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTableWidgetItem>

namespace Ui {
class orderslist;
}

class orderslist : public QWidget
{
    Q_OBJECT

public:
    explicit orderslist(QWidget *parent = nullptr);
    ~orderslist();

private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();

private:
    Ui::orderslist *ui;
    QTcpServer* server;
    QList<QTcpSocket*> clientSockets;
    int selectedRow = -1;
    void sendStatusToClient(int row, const QString &message);
};

#endif // ORDERLIST_H
