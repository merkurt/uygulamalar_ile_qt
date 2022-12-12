#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    kilit = true;

    soket = new QTcpSocket;
    soket->connectToHost("127.0.0.1", 1234);

    ui->textBrowser->append("-+- Baglanti kurulmaya calisiyor. -+-");

    connect(soket, SIGNAL(connected()), this, SLOT(baglantiyiAc()));
    connect(soket, SIGNAL(readyRead()), this, SLOT(hazir()));
    connect(soket, SIGNAL(disconnected()), this, SLOT(baglantiyiKapat()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hazir()
{
    QByteArray veri = soket->readAll();
    ui->textBrowser->append("O: " + veri);
}

void MainWindow::baglantiyiAc()
{
    ui->textBrowser->append("-+- Baglanti kuruldu. -+-");
    kilit = false;
}

void MainWindow::baglantiyiKapat()
{
    ui->textBrowser->append("-+- Baglanti sonlandi. -+-");
    kilit = true;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString temp = ui->lineEdit->text();
    QByteArray tempArray = "";

    for (int i = 0; i < temp.size(); ++i) {
        tempArray.append(temp.at(i));
    }

    ui->textBrowser->append("Sen: " + tempArray);
    ui->lineEdit->setText("");

    if(!kilit){
        soket->write(tempArray);
    }
    else{
        ui->textBrowser->append("-+- Mesaj iletilemedi. -+-");
    }
}
