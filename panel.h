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
    explicit panel(QWidget *parent = nullptr);
    ~panel();

private:
    Ui::panel *ui;
};

#endif // PANEL_H
