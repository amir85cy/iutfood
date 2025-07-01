#ifndef REPORTS_H
#define REPORTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Reports;
}
QT_END_NAMESPACE

class Reports : public QMainWindow
{
    Q_OBJECT

public:
    Reports(QWidget *parent = nullptr);
    ~Reports();

private:
    Ui::Reports *ui;
    void loadUsersFromDatabase();

};
#endif // REPORTS_H
