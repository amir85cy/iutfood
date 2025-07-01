#ifndef EDITUSER_H
#define EDITUSER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Edituser;
}
QT_END_NAMESPACE

class Edituser : public QMainWindow
{
    Q_OBJECT

public:
    Edituser(QWidget *parent = nullptr);
    ~Edituser();

private:
    Ui::Edituser *ui;
    void loadUsersFromDatabase();

private slots:
    void changeUserRole(int rolenum);
    void showSelectedUserInfo();
    void deleteSelectedUser();


};
#endif // EDITUSER_H
