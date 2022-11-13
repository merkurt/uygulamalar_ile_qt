#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void cekilis();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    int sayilar[5];
    int temp, sira, tutan;
};

#endif // MAINWINDOW_H
