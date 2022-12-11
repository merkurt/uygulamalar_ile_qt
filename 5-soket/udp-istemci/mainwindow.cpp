#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soket = new QUdpSocket;
    QByteArray veri;
    veri.append("UDP istemiden bir mesaj gonderdim.");
    soket->writeDatagram(veri, QHostAddress::LocalHost, 1234);
}

MainWindow::~MainWindow()
{
    delete ui;
}
