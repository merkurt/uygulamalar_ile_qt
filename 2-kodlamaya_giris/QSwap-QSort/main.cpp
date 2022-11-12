#include <QCoreApplication>

#include <QtAlgorithms>
#include <QDebug>

QString myS1 = "MyS1";
QString myS2 = "MyS2";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QSwap
    qDebug() << "Swaptan once:" << myS1 << myS2;
    qSwap(myS1, myS2); //pythonda myS1, myS2 = myS2, myS1
    qDebug() << "Swaptan sonra:" << myS1 << myS2;

    qDebug() << "";

    // QSort
    QList<int> myList;
    myList << 3 << 10 << 5 << 55 << 58 << 60 << 1 << 6;
    qDebug() << "Sort oncesi:" << myList;
    qSort(myList);
    qDebug() << "Sort sonrasi:" << myList;

    return a.exec();
}
