#ifndef RESTAURANTCARD_H
#define RESTAURANTCARD_H

#include <QWidget>

namespace Ui {
class RestaurantCard;
}

class RestaurantCard : public QWidget
{
    Q_OBJECT

public:
    explicit RestaurantCard(QWidget *parent = nullptr);
    ~RestaurantCard();

    void setName(const QString &name);
    void setAddress(const QString &address);
    void setCategory(const QString &category);
    void setRating(int rating);

private:
    Ui::RestaurantCard *ui;
};

#endif // RESTAURANTCARD_H
