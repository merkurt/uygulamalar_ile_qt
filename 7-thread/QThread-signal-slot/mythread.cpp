#include "mythread.h"

myThread::myThread(QString param)
{
    name = param;
    qDebug() << name << "isimli thread basladi!";
}

void myThread::run()
{
    for (int i = 0; i < 30000000; ++i) {
        qDebug() << name << " sayac:" << i;
    }
}
