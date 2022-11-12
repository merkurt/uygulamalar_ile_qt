#include <QCoreApplication>

#include <QTimer>
#include <QDebug>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myclass timerClass;

    return a.exec();
}
