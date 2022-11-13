#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void on_sayi_1_clicked();

    void on_sayi_2_clicked();

    void on_sayi_3_clicked();

    void on_sayi_4_clicked();

    void on_sayi_5_clicked();

    void on_sayi_6_clicked();

    void on_sayi_7_clicked();

    void on_sayi_8_clicked();

    void on_sayi_9_clicked();

    void on_sayi_0_clicked();

    void on_islem_toplama_clicked();

    void on_islem_cikartma_clicked();

    void on_islem_carpam_clicked();

    void on_islem_bolme_clicked();

    void on_islem_hesapla_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    double sayi1, sayi2, sonuc;
    int islem;
    bool ilk, kilit;
    QString ekran;

    void sayiEkle(int sayi);
    void kilitle(int islemTuru);
    void hesapla();

};

#endif // MAINWINDOW_H
