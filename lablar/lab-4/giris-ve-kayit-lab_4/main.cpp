#include "mainwindow.h"
#include <QApplication>

#include "giris.h"
#include "kayit.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    giris girisWindow;
    kayit kayitWindow;

    kayitWindow.baglantiyiAC();

    QSqlQuery kullaniciKontrol;

    kullaniciKontrol.exec("SELECT * FROM kullanici");
    kullaniciKontrol.first();

    if(!kullaniciKontrol.isValid()){
        QMessageBox::information(0, "UYARI", "Kayitli kullanici bulunmamaktadir, lutfen kayit olunuz...");
        kayitWindow.show();
    }
    else{
        girisWindow.show();
    }

    return a.exec();
}
