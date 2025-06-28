#include "iutfood_firstpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IUTFood w;
    w.show();
    return a.exec();
}
