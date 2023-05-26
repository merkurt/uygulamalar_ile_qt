#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t1->start();

    connect(t1, SIGNAL(started()), t2, SLOT(terminate()));
    connect(t2, SIGNAL(started()), t1, SLOT(terminate()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(t1->isFinished()){
        t1->start();
    }
    else{
        t2->start();
    }
}
