#include "giris.h"
#include "ui_giris.h"

giris::giris(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giris)
{
    ui->setupUi(this);
}

giris::~giris()
{
    delete ui;
}

void giris::on_pushButton_clicked()
{
    QString tempKullanici, tempSifre;

    tempKullanici = ui->lineEdit_kullanici->text();
    tempSifre = ui->lineEdit_sifre->text();

    QSqlQuery query;
    query.exec("SELECT sifre FROM kullanici WHERE isim='"+tempKullanici+"'");

    query.first();

    QByteArray QBASifre = tempSifre.toLatin1();
    tempSifre = QString(QCryptographicHash::hash((QBASifre), QCryptographicHash::Md5).toHex());

    qDebug() << query.value(0).toString() << tempSifre << (tempSifre == query.value(0).toString());

    if(tempSifre == query.value(0).toString()){
        MainWindow *m = new MainWindow;
        m->show();
        this->hide();
        QSqlDatabase vTabani;
        vTabani.removeDatabase(QSqlDatabase::defaultConnection);
    }
    else{
        QMessageBox::warning(0, "UYARI", "Sifre Eslesmiyor!");
    }
}
