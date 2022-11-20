#include "kayit.h"
#include "ui_kayit.h"

kayit::kayit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kayit)
{
    ui->setupUi(this);
}

kayit::~kayit()
{
    delete ui;
}
