#include "mythread.h"

myThread::myThread(QByteArray threadName, QString fileName)
{
    name = threadName;
    fil = new QFile(fileName);

}

void myThread::run()
{
    for (int i = 0; i < 100; ++i) {
        fil->open(QIODevice::Append);
        fil->write(name + " writing...\n");
        fil->close();
    }
    this->exit();
}
