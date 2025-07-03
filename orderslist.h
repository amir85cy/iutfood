#ifndef ORDERSLIST_H
#define ORDERSLIST_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

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
    void sendStatusToClient(int row, const QString &status);

private:
    Ui::orderslist *ui;
    QTcpServer *server;
    QList<QTcpSocket*> clientSockets;
    int selectedRow = -1;
};

#endif // ORDERSLIST_H
