#include "myclass.h"

myclass::myclass()
{
    say = 1;
    timerObjesi = new QTimer(this);
    connect(timerObjesi, SIGNAL(timeout()), this, SLOT(timerSlotu()));
    timerObjesi->start(1000);
}

void myclass::timerSlotu()
{
    if(say >= 5){
        timerObjesi->stop();
    }
    qDebug() << "Sayiyorum" << say;
    say++;
}
