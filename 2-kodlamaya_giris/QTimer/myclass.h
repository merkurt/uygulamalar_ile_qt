#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class myclass : public QObject
{Q_OBJECT
    QTimer *timerObjesi;
    int say;
public:
    myclass();
public slots:
    void timerSlotu();
};

#endif // MYCLASS_H
