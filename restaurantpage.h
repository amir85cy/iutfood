#ifndef RESTAURANTPAGE_H
#define RESTAURANTPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Restaurantpage; }
QT_END_NAMESPACE

class Restaurantpage : public QWidget
{
    Q_OBJECT

public:
    explicit Restaurantpage(QWidget *parent = nullptr);
    ~Restaurantpage();
public slots:
    void addSelectedFoodToCart();

private:
    Ui::Restaurantpage *ui;
    void loadRestaurantInfo();
    void loadData();

    QString restaurantusername;
    void likeSelectedComment();
};

#endif // RESTAURANTPAGE_H
