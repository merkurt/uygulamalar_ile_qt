#include "mythread.h"

myThread::myThread(QString param)
{
    name = param;

    qDebug() << name << "isimli thread olusturuldu!";
}

void myThread::run()
{
    for (int i = 0; i <= 1000; ++i) {
        qDebug() << name << "thread:" << i;
    }
}
