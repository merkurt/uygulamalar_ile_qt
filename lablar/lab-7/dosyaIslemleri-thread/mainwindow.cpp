#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(timerFoo()));

    QString fileName = QDir::currentPath() + "/dosya.txt";

    file = new QFile(fileName);
    file->remove();

    myThread *t1 = new myThread("thread-1", fileName);
    myThread *t2 = new myThread("thread-2", fileName);

    t1->start();
    t2->start();

    timer->start(1);

    connect(t2, SIGNAL(finished()), timer, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerFoo()
{
    file->open(QIODevice::ReadOnly);
    ui->textBrowser->setText(file->readAll());
    file->close();
}
