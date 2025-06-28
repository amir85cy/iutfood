#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QWidget>

namespace Ui {
class Signinwindow;
}
void errormsg();
class Signinwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Signinwindow(QWidget *parent = nullptr);
    ~Signinwindow();

private:
    Ui::Signinwindow *ui;
};

#endif // SIGNINWINDOW_H
