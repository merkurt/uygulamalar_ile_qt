#include <QCoreApplication>

#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString myString = "merhaba qt!";
    qDebug() << "Ilk debug: " << myString;

    return a.exec();
}
