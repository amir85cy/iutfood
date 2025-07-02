#ifndef MANAGEMENU_H
#define MANAGEMENU_H

#include <QWidget>

namespace Ui {
class managemenu;
}

class managemenu : public QWidget
{
    Q_OBJECT

public:
    explicit managemenu(QWidget *parent = nullptr);
    ~managemenu();

private:
    Ui::managemenu *ui;
private slots:
    void deleteSelectedRow();
};

#endif // MANAGEMENU_H
