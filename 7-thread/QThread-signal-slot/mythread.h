#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class myThread : public QThread
{
public:
    myThread(QString param);

    void run();

    QString name;
};

#endif // MYTHREAD_H
