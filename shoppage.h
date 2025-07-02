#ifndef SHOPPAGE_H
#define SHOPPAGE_H

#include <QWidget>

namespace Ui {
class ShopPage;
}

class ShopPage : public QWidget
{
    Q_OBJECT

public:
    explicit ShopPage(QWidget *parent = nullptr);
    ~ShopPage();

private:
    Ui::ShopPage *ui;

    void loadRestaurants();
};

#endif // SHOPPAGE_H
