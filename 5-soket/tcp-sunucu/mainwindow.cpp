#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sunucu = new QTcpServer(this);

    connect(sunucu, SIGNAL(newConnection()), this, SLOT(yeniBaglanti()));

    if(sunucu->listen(QHostAddress::Any, 1234)){
        qDebug() << "Sunucu baslatildi.";
    }
    else{
        qDebug() << "Sunucu baslatilirken hata!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::yeniBaglanti()
{
    soket = sunucu->nextPendingConnection();
    soket->waitForBytesWritten();

    connect(soket, SIGNAL(readyRead()), this, SLOT(hazir()));
    connect(soket, SIGNAL(disconnected()), this, SLOT(baglantiyiKapat()));
}

void MainWindow::hazir()
{
    QByteArray veri = soket->readAll();
    qDebug() << veri;
    ui->label->setText(veri);
}

void MainWindow::baglantiyiKapat()
{
    qDebug() << "Baglanti sonlandirildi.";
}
