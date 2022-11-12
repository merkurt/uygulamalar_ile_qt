# uygulamalar_ile_qt

## QT Sınıfları
### QString ve QDebug 
* QString std::string yerine kullanılır. Tüm qt fonksiyonları ile uyumludur ve hızlıdır.
* QDebug hata ayıklama amacıyla geliştiriciye kolaylık sağlar. "Application Output" bölümünde veri yapılarının ve fonksiyonların çıkış değerlerinin gösterilmesini sağlayan C++ sınıfıdır.

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