#ifndef GIRIS_H
#define GIRIS_H

#include <QWidget>

#include <QtSql>
#include <qcryptographichash.h>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class giris;
}

class giris : public QWidget
{
    Q_OBJECT

public:
    explicit giris(QWidget *parent = 0);
    ~giris();

private slots:
    void on_pushButton_clicked();

private:
    Ui::giris *ui;
};

#endif // GIRIS_H
