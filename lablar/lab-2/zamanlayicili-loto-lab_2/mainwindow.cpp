#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << time(NULL);
    qsrand(time(NULL));

    //0-30 arasında 5 adet sayi uretiyoruz
    for(int i = 0; i < 5; i++){
        sayilar[i] = qrand() % 30;
    }
    qDebug() << "Kuponunuz:" << sayilar[0]
                             << sayilar[1]
                             << sayilar[2]
                             << sayilar[3]
                             << sayilar[4];

    sira = 0;
    tutan = 0;

    timer = new     QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(cekilis()));
    timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cekilis()
{
    qsrand(time(NULL));
    temp = qrand() % 30;

    qDebug() << "sayi" << sira + 1 << "cekiliyor ve" << temp;

    for(int i = 0; i < 5; i++){
        if(sayilar[i] == temp){
            qDebug() << "Tuttu!";
            tutan++;
            break;
        }
    }

    sira++;

    if(sira == 5){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(cekilis()));
        qDebug() << tutan << "sayi tutturdunuz!";
    }
}
