#ifndef RESTAURATEURPAGE_H
#define RESTAURATEURPAGE_H

#include <QWidget>

namespace Ui {
class Restaurateurpage;
}

class Restaurateurpage : public QWidget
{
    Q_OBJECT

public:
    explicit Restaurateurpage(QWidget *parent = nullptr);
    ~Restaurateurpage();

private:
    Ui::Restaurateurpage *ui;
    void loadRestaurants();
};

#endif // RESTAURATEURPAGE_H
