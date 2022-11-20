#include "kayit.h"
#include "ui_kayit.h"

kayit::kayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kayit)
{
    ui->setupUi(this);
}

kayit::~kayit()
{
    delete ui;
}

bool kayit::baglantiyiAC()
{
    veritabani = QSqlDatabase::addDatabase("QSQLITE");
    veritabani.setDatabaseName("..\\veritabani.db");

    if(veritabani.open()){
        qDebug() << "Veri tabanina baglanildi.";
        return true;
    }
    else{
        qDebug() << "Veri tabanina baglanilamadi.";
        baglantiyiKapat();
        return false;
    }
}

void kayit::baglantiyiKapat()
{
    veritabani.close();
    veritabani.removeDatabase(QSqlDatabase::defaultConnection);
}

void kayit::on_pushButton_clicked()
{
    QString tempKullanici, tempSifre;

    tempKullanici = ui->lineEdit_kullanici->text();
    tempSifre = ui->lineEdit_sifre->text();

    QByteArray QBASifre = tempSifre.toLatin1();
    tempSifre = QString(QCryptographicHash::hash(QBASifre, QCryptographicHash::Md5).toHex());

    QSqlQuery query;

    query.exec("INSERT INTO kullanici(isim, sifre) VALUES('"+tempKullanici+"', '"+tempSifre+"')");

    if(query.isActive()){
        MainWindow *m = new MainWindow;
        m->show();
        this->hide();
        this->baglantiyiKapat();
    }
    else{
        QMessageBox::warning(0, "UYARI", "Kayit olurken hata meydana geldi!");
    }
}
