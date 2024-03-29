# Sunuş
Qt ile olan geçmişimiz üniversite öğrenimimin ilk yıllarına dayanıyor. Python üzerinde bolca kullandıktan sonra C++ yeteneklerimi biraz daha geliştirebilmek için C++ ile QT kullanmaya devam ettim. Daha sonra projeler ve elimdeki işler sebebiyle uzunca bir süre QT'yi C++ ile birlikte kullanmadım. Geçtiğimiz günlerde Serhat Deniz ÖZTÜRK'ün "Uygulamalar ile QT" kitabını, D&R'da buldum ve aldım. Boş zamanlarımda bilgilerimi tazelemek ve bu sırada ihtiyaç duyduğumda kolayca bu bilgilere yeniden ulaşabilmek adına tuttuğum notları herkese açmamın daha faydalı olacağını düşünüyorum. Sadece benim ulaşabileceğim gizli bir repository'de kalmasındansa bu konuda araştırma yapan bir kişiye dahi faydası olabilirse ne mutlu.

# QT Sınıfları
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

# SQLite
### SQLite Browser
* SQLite Browser ile veritabanlarınızı yönetebilirsiniz. [SQLite Browser](https://sqlitebrowser.org)
* SQLite veritabanlarının uzantılarının bir önemi yoktur. Genelde `.sqlite`, `sql3` veya `.db` kullanılır.
### SQLite QT entegrasyonu
* Projeye SQLite'ı entegre etmek için `.pro` uzantılı proje dosyasına `QT += sql` komutu eklenir.
```
QT += core gui sql
```
* Ardından `header` dosyasına `#include <QtSql>` eklenir.
* Veri tabanı için `QSqlDatabase` tipinde global bir değişkene ihtiyaç vardır.
```
QSqlDatabase veritabani;
```
* Veri tabanına bağlanmak için:
```
veritabani = QSqlDatabase::addDatabase("QSQLITE");
veritabani.setDatabaseName('database_konumu');
veritabani.open();
```
* Veri tabanından ayrılmak için:
```
veritabani.close();
veritabani.removeDatabase(QSqlDatabase::defaultConnection);
```
* Veri tabanında SQL komutları çalıştırmak:
```
QSqlQuery qry;
qry.exec("SQL KOMUTU");
```
### Table View Widget Bağlantısı
* `.ui` dosyasına `Table View Widget` eklenir.
```
QSqlQuery *qry = new QSqlQuery;

qry->exec("SELECT * FROM * tablo_ismi");

QSqlQueryModel *model_tablo = new QSqlQueryModel;

model_tablo->setQuery(*qry);
ui->tableView->setModel(model_tablo);
```
* Aynı zamanda tabloyu yenilemek için de bu kod parçası kullanılabilir.
### Değişkenler ile SQL komutları çalıştırmak
* Değişkenler `'"+degisken+"'` şeklinde ifade edilir.
```
qry.exec("INSERT INTO tablo(val1, val2) VALUES('"+val1+"', '"+val2+"')");
```
[SQLite Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/4-veritabani/veritabani-sqlite)

# Soket
* Soketler ile çalışmak için `.pro` uzantılı proje dosyasına `QT += network` komutu eklenmelidir.
## TCP Sunucusu
* `header` dosyası içerisine `#include <QTcpServer>` ve `#include <QTcpSoket>` eklenir.
* Yine `header` dosyasına `QTcpServer *sunucu` ve `QTcpSoket *soket` ile ilgili nesneler tanımlanır.
* Soket üzerinden `newConnection()`, `readyRead()` ve `disconnected()` gibi birçok `SIGNAL` üretilebilir. Örneğin,
```
connect(sunucu, SIGNAL(newConnection()), this, SLOT(yeniBaglanti()));
connect(sunucu, SIGNAL(readyRead()), this, SLOT(hazir()));
connect(sunucu, SIGNAL(disconnected(), this, SLOT(baglantiyiKapat())));
```
* Localhost üzerinde 1234 portunu dinlemek için
```
sunucu->listen(QHostAddress::Any, 1234)
```
* Sunucuya yeni bağlantı geldiğinde üretilen `SIGNAL` ile aşağıdaki fonksiyon tetiklenir.
```
void MainWindow::yeniBaglanti()
{
    soket = sunucu->nextPendingConnection();
    soket->waitForBytesWritten();
}
```
* Sunucuya yeni bağlantı geldiğinde üretilen `SIGNAL` ile aşağıdaki fonksiyon tetiklenir.
```
void MainWindow::yeniBaglanti()
{
    soket = sunucu->nextPendingConnection();
    soket->waitForBytesWritten();
}
```
Burada `sunucu->nextPendingConnection()` sıradaki bağlantıyı döndürür. `soket->waitForBytesWritten()` ise gelecek veri için bekletir.
* Sunucuya yeni veri geldiğinde `SIGNAL` ile aşağıdaki fonksiyon tetiklenir.
```
void MainWindow::hazir()
{
    QByteArray veri = soket->readAll();
    qDebug() << veri;
}
```
[TCP Sunucu Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/5-soket/tcp-sunucuQ)
## TCP İstemcisi
* `header` dosyası içerisine `#include <QTcpSocket>` eklenir.
* Yine `header` dosyası içerisine `QTcpSocket *soket` şeklinde soket nesnesi tanımlanır.
* 1234 portu üzerinden localhost'a bağlanmak için,
```
soket = new QTcpSocket;
soket->connectToHost("127.0.0.1", "1234");
```
* Soket üzerinden veri göndermek için,
```
// QByteArray veri;
soket->write(veri);
```
[TCP İstemci Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/5-soket/tcp-istemci)

## UDP Sunucusu
* `header` dosyasına `#include <QUdpSocket>` ekliyoruz.
* Yine `header` dosyasına `QUdpSocket *soket` ile soket nesnesini tanımlıyoruz.
* İstemciden veri geldiğinde tetiklenecek olan `hazir()` fonksiyonunu tanımlıyoruz ve bağlıyoruz.
    * `header` dosyasına,
    ```
    public slots:
        void hazir();
    ```
    * `cpp` dosyasında `MainWindow` constructor fonksiyonuna,
    ```
    connect(soket, SIGNAL(readyRead()), this, SLOT(hazir()));
    ```
* 1234 portundan localhost'a bind olmak için
```
soket = new QUdpSocket;
soket->bind(QHostAddress::LoalHost, 1234);
```
* Gelen verilerin okunması,
```
QByteArray data;
data.resize(soket->pendingDatagramSize());
QHostAddress address;
quint16 port;
soket->readDatagram(data.data(), data.size(), &address, &port);
```
[UDP Sunucu Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/5-soket/udp-sunucu)
## UDP İstemcisi
* `header` dosyasına `#include <QUdpSocket>` ekliyoruz.
* Yine `header` dosyasına `QUdpSocket *soket` ile soket nesnesini tanımlıyoruz.
* Sunucuya bir datagram göndermek için,
```
soket = new QUdpSocket;
QByteArray veri;
veri.append("Bu bir mesajdir.");
soket->writeDatagram(veri, QHostAddress::LocalHost, 1234);
```
[UDP istemci Örnek](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/5-soket/udp-istemci)

# QThread
* Yeni bir C++ class'ı oluşturulur (Örn: `myThread`).
* `header` dosyasına `#include <QThread>` eklenir.
* Class tanımının sağ tarafına `: public QThread` ekleneerek QThread sınıfı miras alınır.
```
class myThread : public QThread
{
public:
    myThread();
}
```
* Class tanımının içerisine `run` isimli bir metot tanımlanır. İlgili metot `QThread` sınıfına ait `run()` metodunu `override` eder ve `start()` metodu çağırılığında thread bu `run()` metodunu koşturur.
```
class myThread : public QThread
{
public:
    myThread();
    void run();
};
```
```
void myThread::run()
{
    // do something..
}

```
* Bir thread `start(priority)` ile başlatılır. 
```
myThread* thread1 = new myThread();
thread1->start();
```
* `start()` metodu argüman olarak thread'in önceliğini alır. 
    - QThread::IdlePriority
    - QThread::LowestPriority
    - QThread::LowPriority
    - QThread::NormalPriority
    - QThread::HighPriority
    - QThread::HighestPriority
    - QThread::TimeCriticalPriority
    - QThread::InheritPriority

    <br>Boş bırakıldığında öncelik `QThread::InheritPriority` olur.

* Priority `run-time` sırasında da değiştirilebilir.
```
thread1->setPriority(QThread::TimeCriticalPriority);
```
## QThread Signal ve Slot
* Threadler çeşitli signal ve slotlara sahiptir. Böylece birbirleri arasında senkronizasyon veya başlangıç-bitiş gibi durumlarda koşturulacak kod parçaları organize edilebilir.
```
myThread* thread1 = new myThread();
myThread* thread2 = new myThread();

thread1->start();
connect(thread1, SIGNAL(started()), thread2, SLOT(terminate()));
connect(thread2, SIGNAL(started()), thread1, SLOT(terminate()));
```
[QThread Sayıcı](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/7-thread/QThread)
[QThread Signal ve Slot](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/7-thread/QThread-signal-slot)

# Lablar
## Lab-1
* [Temel konsol uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-1/temel-konsol_uygulamasi-lab_1)
* [Temel widget uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-1/temel-widget-uygulamasi-lab_1)
## Lab-2
* [Zamanlayıcılı Loto](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-2/zamanlayicili-loto-lab_2)
## Lab-3
* [Hesap makinesi](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-3/hesap-makinesi-lab_3)
## Lab-4
* [Giriş ve Kayıt Uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-4/giris-ve-kayit-lab_4)
## Lab-5
* [Dosyadaki Tükçe Karakterleri Değiştirme](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-5/metin-dosyasi-lab_5)
    * Burada input file not defteri ile output file ise farklı bir text editör ile açılmalıdır.
## Lab-6
* [Basit Sohbet Uygulaması](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-6/basitSohbetUygulamasi)
* [Basit Sohbet Uygulaması - Server](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-6/basitSohbetUygulamasi-server)
## Lab-7
*  [Thread ile Dosya İşlemleri](https://github.com/merkurt/uygulamalar_ile_qt/tree/main/lablar/lab-7/dosyaIslemleri-thread)
