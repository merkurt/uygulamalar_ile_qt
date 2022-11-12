#include <QCoreApplication>

#include <QCryptographicHash>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCryptographicHash myHash(QCryptographicHash::Md4);
    myHash.addData("OMER-KURT");
    qDebug() << "Raw:" << myHash.result();
    qDebug() << "Hex:" << myHash.result().toHex();

    return a.exec();
}
