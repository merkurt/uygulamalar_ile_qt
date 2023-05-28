#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QFile>
#include <QString>
#include <QDir>

class myThread : public QThread
{
public:
    myThread(QByteArray threadName, QString fileName);

    QByteArray name;
    QFile *fil;

    void run();
};

#endif // MYTHREAD_H
