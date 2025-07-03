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
    QTcpSocket *socket;

    void loadCartItems(const QString &filename);
    void updateTotalPrice();
    void updateCartFile(const QString &filename);
    void removeSelectedItem();
};

#endif // CART_H
