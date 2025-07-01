#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QWidget>

namespace Ui {
class Adminpage;
}

class Adminpage : public QWidget
{
    Q_OBJECT

public:
    explicit Adminpage(QWidget *parent = nullptr);
    ~Adminpage();

private:
    Ui::Adminpage *ui;
};

#endif // ADMINPAGE_H
