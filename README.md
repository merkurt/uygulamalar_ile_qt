# uygulamalar_ile_qt

## QT Sınıfları
### QString ve QDebug 
* QString std::string yerine kullanılır. Tüm qt fonksiyonları ile uyumludur ve hızlıdır.
* QDebug hata ayıklama amacıyla geliştiriciye kolaylık sağlar. "Application Output" bölümünde veri yapılarının ve fonksiyonların çıkış değerlerinin gösterilmesini sağlayan C++ sınıfıdır.
[Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QString-QDebug)
### Signal ve Slot
* Oluşan sinyali ilgili slot fonksiyonuna iletir. Bir nevi QT içerisindeki tetikleme mekanizmasıdır. Özellikle arayüz geliştirme ve soket programlama yapılırken önemli rol oynar.
>
    connect(server, SIGNAL(newConnection()), this, SLOT(connectTo()));

Bu fonksiyon dört parametre alır: sinyalin geldiği obje, signal, slotun üzerinde bulunduğu obje ve slot.

### QTimer
* Zamanlama için kullanılan bir C++ sınıfıdır. Kullanmadan önce başlık dosyasına `#include <QTimer>` eklenir.
* Eğer "QT Console Application" projesi içeriisnde yazılacaksa `#include <QObject>` eklenmesi ve sınıf tanımlamasının yanına  `public QObject` yazılmalı. Ardından sınıf içerisinde de `Q_OBJECT` makrosu eklenmeli.
    ```
    // myclass.h
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
    ```
    ```
    // myclass.cpp
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

    ```
    [Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QTimer)
* Eğer "QT Widgets Application" projesi içerisinde yazılacaksa bunlara gerek yoktur.

## Konteyner Sınıfları
QT içerisinde QStack, QQueue, QList, QVector, QHash gibi konteyner sınıfları barındırır. Bu sınıflar projeye dahil edilerek QT ile verimli bir şekilde kullanılır.
### QStack
* `#include <QStack>` ile dahil edilir. Kendisine has dört fonksiyonu bulunmaktadır: pop, push, swap ve top.
* QVector'ün fonksiyonlarını kalıtım ile kullanabilir. Böylece stack'in önünde veri eklenebilir veya boş olup olmadığı kontrol edilebilir.
[Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QStack)

### QHash
* Veriler kendilerine has key'ler ile tutulur ve bu keyler ile verilere kolayca ulaşılabilir.
* `#include <QHash>` ile dahil edilir.
[Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QHash)

## Algoritmalar
QT içerisindeki algoritmalardır. `#include <QtAlgorithms>` bünyesindedirler.
### QSwap
* İki değişkenin değerlerini birbiri ile değiştirir. Pythonda `a, b = b, a` ifadesine denktir.
### QSort
* Bu fonksiyon ile konteyner nesneleri rahatlıkla sıralanabilir.

[Algoritmalar dokümanı](https://doc.qt.io/qt-5/qtalgorithms-obsolete.html)

[Örnekler](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QSwap-QSort)

## Tarih ve Saat
### QTime
* `#include <QTime>` şeklinde dahil edilir. Zaman ile ilgili işlemler için kullanılır.
### QDate
* `#include <QDate>` şeklinde dahil edilir. Tarih ile ilgili işlemler için kullanılır.
### QDateTime
* `#include <QDateTime>` şeklinde dahil edilir. Tarih ve zaman  ile ilgili işlemler için kullanılır.
[Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QTime-QDate-QDateTime)

## Rastgele Sayı Üretmek
### qrand
* `qrand()` rastgele sayı üretmek için kullanılan fonksiyondur. `qrand() % ust_limit` şeklinde kullanılır.
```
//0-10 arası rastgele bir sayı üretmek
qDebug() << "Rastgele sayi:" << qrand() % 10;
```

## Şifreli Hash
### QCryptographicHash
* Kriptografik hash üretmek için kullanılır. `#include <QCryptographicHash>` şeklinde dahil edilir.
[Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/2-kodlamaya_giris/QCryptographicHash)


# Lablar
## Lab-1
* [Temel konsol uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-1/temel-konsol_uygulamasi-lab_1)
* [Temel widget uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-1/temel-widget-uygulamasi-lab_1)