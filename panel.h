#ifndef PANEL_H
#define PANEL_H

#include <QWidget>

namespace Ui {
class panel;
}

class panel : public QWidget
{
    Q_OBJECT

public:
    explicit panel(const QString &username, QWidget *parent = nullptr);
    ~panel();

private:
    Ui::panel *ui;

    QString currentUsername;  // نام کاربری لاگین‌شده برای پیگیری و ثبت در دیتابیس
};

#endif // PANEL_H
