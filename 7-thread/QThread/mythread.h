#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class myThread : public QThread
{
public:
    myThread(QString param);

        /*  run metodunun yatay gosterilmesinin sebebi
            thread sinifinin icerisinde run isimli bir metodun
            olması ve bizim yazdigimiz run metodu onu override
            ediyor olusudur. run metodu start metodu icerisinde
            cagirilir   */
    void run();

    QString name;
};

#endif // MYTHREAD_H
