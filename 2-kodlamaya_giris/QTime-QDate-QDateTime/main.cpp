#include <QCoreApplication>

#include <QTime>
#include <QDate>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTime zaman;
    zaman = QTime::currentTime();
    qDebug() << "QTime" << zaman;

    QDate tarih;
    tarih = QDate::currentDate();
    qDebug() << "QDate" << tarih;

    QDateTime tarihSaat;
    tarihSaat = QDateTime::currentDateTime();
    qDebug() << "Tarih ve Saat" << tarihSaat;

    return a.exec();
}
