#ifndef KAYIT_H
#define KAYIT_H

#include <QWidget>

#include <QDebug>
#include <QtSql>
#include <QCryptographicHash>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class kayit;
}

class kayit : public QWidget
{
    Q_OBJECT

public:
    explicit kayit(QWidget *parent = 0);
    QSqlDatabase veritabani;

    bool baglantiyiAC();
    void baglantiyiKapat();

    ~kayit();

private slots:
    void on_pushButton_clicked();

private:
    Ui::kayit *ui;


};

#endif // KAYIT_H
