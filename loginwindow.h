#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void errormsg(const QString &matn);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
