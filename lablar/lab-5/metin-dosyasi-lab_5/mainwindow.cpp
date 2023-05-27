#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dosyaDuzelt()
{
    QFile kaynakDosya(kaynakAdresi);
    kaynakDosya.open(QIODevice::ReadOnly);
    QTextStream yayinKaynak(&kaynakDosya);

    QFile ciktiDosya(ciktiAdresi);
    ciktiDosya.open(QIODevice::WriteOnly);
    QTextStream yayinCikti(&ciktiDosya);

    QString okunan;

    while(!yayinKaynak.atEnd()){
        okunan = yayinKaynak.readLine();
        ui->giris_textBrowser->append(okunan);
        okunan = this->harfDuzelt(okunan);
        yayinCikti << okunan << endl;
        ui->cikis_textBrowser->append(okunan);
    }
}

QString MainWindow::harfDuzelt(QString metin)
{
    int boyut = metin.size();

    for (int i = 0; i < boyut; ++i) {
        if(metin[i] == 'ğ') {metin[i] = 'g';}
        else if(metin[i] == 'Ğ') {metin[i] = 'G';}
        else if(metin[i] == 'ü') {metin[i] = 'u';}
        else if(metin[i] == 'Ü') {metin[i] = 'U';}
        else if(metin[i] == 'ö') {metin[i] = 'o';}
        else if(metin[i] == 'Ö') {metin[i] = 'O';}
        else if(metin[i] == 'ş') {metin[i] = 's';}
        else if(metin[i] == 'Ş') {metin[i] = 'S';}
        else if(metin[i] == 'ç') {metin[i] = 'c';}
        else if(metin[i] == 'Ç') {metin[i] = 'C';}
        else if(metin[i] == 'İ') {metin[i] = 'I';}
        else if(metin[i] == 'ı') {metin[i] = 'i';}
    }

    return metin;
}

void MainWindow::on_donustur_pushButton_clicked()
{
    kaynakAdresi = ui->kaynak_lineEdit->text();
    ciktiAdresi = ui->cikti_lineEdit->text();
    this->dosyaDuzelt();
}
