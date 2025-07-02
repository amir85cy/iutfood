#ifndef CART_H
#define CART_H

#include <QWidget>

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
};

#endif // CART_H
