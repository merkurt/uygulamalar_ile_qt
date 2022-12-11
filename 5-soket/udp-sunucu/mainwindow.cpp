#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soket = new QUdpSocket;
    soket->bind(QHostAddress::LocalHost, 1234);
    connect(soket, SIGNAL(readyRead()), this, SLOT(hazir()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hazir()
{
    QByteArray veri;
    veri.resize(soket->pendingDatagramSize());

    QHostAddress address;
    quint16 port;

    soket->readDatagram(veri.data(), veri.size(), &address, &port);

    qDebug() << "Paket Alindi:";
    qDebug() << "Adres:" << address;
    qDebug() << "Port:" << port;
    qDebug() << "Data:" << veri;
}
