#ifndef IUTFOOD_FIRSTPAGE_H
#define IUTFOOD_FIRSTPAGE_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui {
class IUTFood;
}
QT_END_NAMESPACE

class IUTFood : public QMainWindow
{
    Q_OBJECT

public:
    IUTFood(QWidget *parent = nullptr);
    ~IUTFood();

private:
    Ui::IUTFood *ui;
};
#endif // IUTFOOD_FIRSTPAGE_H
