#include <QCoreApplication>

#include <QHash>
#include <QList>
#include <QDebug>

#define YAZILIMCILAR 1
#define YAZICILAR    2
#define DONANIMCILAR 3

void debugQList(QList<QString>* list, const char* name){
    qDebug() << name;
    while(!list->isEmpty()){
        qDebug() << list->takeLast();
    }
    qDebug() << "";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<int, QString> myHash;

    myHash.insert(1, "Omer");
    myHash.insertMulti(1, "Furkan");

    myHash.insert(2, "Basri");

    myHash.insert(3, "Berat");
    myHash.insertMulti(3, "Emre");
    myHash.insertMulti(3, "Arslan");

    QList<QString> yazilimcilar = myHash.values(YAZILIMCILAR);
    debugQList(&yazilimcilar, "Yazilimcilar");

    QList<QString> yazicilar = myHash.values(YAZICILAR);
    debugQList(&yazicilar, "Yazicilar");

    QList<QString> donanimcilar = myHash.values(DONANIMCILAR);
    debugQList(&donanimcilar, "Donanimcilar");

    return a.exec();
}
