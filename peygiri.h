#ifndef PEYGIRI_H
#define PEYGIRI_H

#include <QWidget>

namespace Ui {
class peygiri;
}

class peygiri : public QWidget
{
    Q_OBJECT

public:
    explicit peygiri(QWidget *parent = nullptr);
    ~peygiri();

private:
    Ui::peygiri *ui;
};

#endif // PEYGIRI_H
