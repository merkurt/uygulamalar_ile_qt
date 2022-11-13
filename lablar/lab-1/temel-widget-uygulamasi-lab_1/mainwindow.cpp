#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <dialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Dialog *pencere = new Dialog(this);
    pencere->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
