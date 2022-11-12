# uygulamalar_ile_qt

## 2- Kodlamaya Giriş
### QString ve QDebug 
* QString std::string yerine kullanılır. Tüm qt fonksiyonları ile uyumludur ve hızlıdır.
* QDebug hata ayıklama amacıyla geliştiriciye kolaylık sağlar. "Application Output" bölümünde veri yapılarının ve fonksiyonların çıkış değerlerinin gösterilmesini sağlayan C++ sınıfıdır.

### Signal ve Slot
* Oluşan sinyali ilgili slot fonksiyonuna iletir. Bir nevi QT içerisindeki tetikleme mekanizmasıdır. Özellikle arayüz geliştirme ve soket programlama yapılırken önemli rol oynar.
>
    connect(server, SIGNAL(newConnection()), this, SLOT(connectTo()));

Bu fonksiyon dört parametre alır: sinyalin geldiği obje, signal, slotun üzerinde bulunduğu obje ve slot.