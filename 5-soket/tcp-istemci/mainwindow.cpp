#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    soket = new QTcpSocket;
    soket->connectToHost("127.0.0.1", 1234);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString tempString = ui->lineEdit->text();
    QByteArray tempByteArray;
    tempByteArray.append(tempString);
    soket->write(tempByteArray);
}
