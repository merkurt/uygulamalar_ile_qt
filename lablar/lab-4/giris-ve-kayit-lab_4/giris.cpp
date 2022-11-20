#include "giris.h"
#include "ui_giris.h"

giris::giris(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::giris)
{
    ui->setupUi(this);
}

giris::~giris()
{
    delete ui;
}
