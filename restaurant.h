#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <QWidget>

namespace Ui {
class restaurant;
}

class restaurant : public QWidget
{
    Q_OBJECT

public:
    explicit restaurant(QWidget *parent = nullptr);
    ~restaurant();

private:
    Ui::restaurant *ui;
    void changestatus(int newstst);
    void loadRestaurantsFromDatabase();
};

#endif // RESTAURANT_H
