#ifndef GLOBAL_H
#define GLOBAL_H


#include <QWidget>
#include <QTcpSocket>

extern QString loggedInUsername;  // اعلام متغیر سراسری
extern int selectedRestaurantId;
extern QTcpSocket* globalSocket;

#endif // GLOBAL_H
