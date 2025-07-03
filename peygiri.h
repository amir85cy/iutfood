#ifndef PEYGIRI_H
#define PEYGIRI_H

#include <QWidget>
#include <QTcpSocket>

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
    QTcpSocket *socket;

private slots:
    void onReadyRead();
};

#endif // PEYGIRI_H
