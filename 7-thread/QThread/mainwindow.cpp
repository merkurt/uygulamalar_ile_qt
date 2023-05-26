#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myThread* t1 = new myThread("Thread-1");
    myThread* t2 = new myThread("Thread-2");
    myThread* t3 = new myThread("Thread-3");

    t1->start();

    qDebug() << t1->name << "default priority:" << t1->priority();
    t1->setPriority(QThread::TimeCriticalPriority);
    qDebug() << t1->name << "new priority:" << t1->priority();

    t2->start(QThread::NormalPriority);
    t3->start(QThread::LowestPriority);
}

MainWindow::~MainWindow()
{
    delete ui;
}
