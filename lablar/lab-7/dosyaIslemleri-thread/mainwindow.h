#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QTimer>

#include <mythread.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *timer;
    QFile *file;

public slots:
    void timerFoo();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
