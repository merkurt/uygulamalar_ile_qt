#ifndef MYCLASS_H
#define MYCLASS_H

#include <QString>

class myclass
{
public:
    void setName(QString input);
    QString getName();
private:
    QString name;
};

#endif // MYCLASS_H
