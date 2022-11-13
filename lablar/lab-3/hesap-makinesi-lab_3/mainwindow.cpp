#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ekran = "";
    sayi1 = 0;
    sayi2 = 0;
    sonuc = 0;
    ilk = true;
    kilit = true;
    islem = 4;

    ui->islemSTR ->setText(ekran);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sayi_1_clicked()
{
    sayiEkle(1);
}

void MainWindow::on_sayi_2_clicked()
{
    sayiEkle(2);
}

void MainWindow::on_sayi_3_clicked()
{
    sayiEkle(3);
}

void MainWindow::on_sayi_4_clicked()
{
    sayiEkle(4);
}

void MainWindow::on_sayi_5_clicked()
{
    sayiEkle(5);
}

void MainWindow::on_sayi_6_clicked()
{
    sayiEkle(6);
}

void MainWindow::on_sayi_7_clicked()
{
    sayiEkle(7);
}

void MainWindow::on_sayi_8_clicked()
{
    sayiEkle(8);
}

void MainWindow::on_sayi_9_clicked()
{
    sayiEkle(9);
}

void MainWindow::on_sayi_0_clicked()
{
    sayiEkle(0);
}

void MainWindow::on_islem_toplama_clicked()
{
    if(!kilit){
        kilitle(0);
    }
}

void MainWindow::on_islem_cikartma_clicked()
{
    if(!kilit){
        kilitle(1);
    }
}

void MainWindow::on_islem_carpam_clicked()
{
    if(!kilit){
        kilitle(3);
    }
}

void MainWindow::on_islem_bolme_clicked()
{
    if(!kilit){
        kilitle(2);
    }
}

void MainWindow::on_islem_hesapla_clicked()
{
    hesapla();
}

void MainWindow::sayiEkle(int sayi)
{
    if(ilk){
        sayi1 = sayi1 * 10 + sayi;
    }
    else{
        sayi2 = sayi2 * 10 + sayi;
    }
    ekran = ekran + QString::number(sayi);
    ui->islemSTR->setText(ekran);
    kilit = false;
}

void MainWindow::kilitle(int islemTuru)
{
    islem = islemTuru;
    switch (islemTuru) {
    case 0:
        ekran = ekran + " + ";
        break;
    case 1:
        ekran = ekran + " - ";
        break;
    case 2:
        ekran = ekran + " / ";
        break;
    case 3:
        ekran = ekran + " x ";
    default:
        break;
    }
    kilit = true;
    ilk = false;
    ui->islemSTR->setText(ekran);
}

void MainWindow::hesapla()
{
    if(islem == 0){
        sonuc = sayi1 + sayi2;
    }
    else if(islem == 1){
        sonuc = sayi1 - sayi2;
    }
    else if(islem == 2){
        sonuc = sayi1 / sayi2;
    }
    else if(islem == 3){
        sonuc = sayi1 * sayi2;
    }
    else{
        ;
    }
    ui->lcdNumber->display(sonuc);
}

void MainWindow::on_pushButton_clicked()
{
    ekran = "";
    sayi1 = 0;
    sayi2 = 0;
    sonuc = 0;
    ilk = true;
    kilit = true;
    islem = 4;
    ui->islemSTR->setText(ekran);
    ui->lcdNumber->display(0);
}
