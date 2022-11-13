#include <QCoreApplication>

#include <QDebug>

#include "myclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myclass mc;

    mc.setName("OMER-KURT");
    qDebug() << mc.getName();

    return a.exec();
}
