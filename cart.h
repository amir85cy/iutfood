// cart.h
#ifndef CART_H
#define CART_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class cart;
}

class cart : public QWidget
{
    Q_OBJECT

public:
    explicit cart(QWidget *parent = nullptr);
    ~cart();

private:
    Ui::cart *ui;
    void loadCartItems(const QString &filename);
    void updateTotalPrice();
    void removeSelectedItem();
    void updateCartFile(const QString &filename);
    QTcpSocket* socket;

};

#endif // CART_H
