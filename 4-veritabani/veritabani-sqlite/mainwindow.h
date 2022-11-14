#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSql>

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

    void on_buton_ekle_clicked();

    void on_tableView_pressed(const QModelIndex &index);

    void on_buton_duzenle_clicked();

    void on_buton_sil_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase veritabani;
    QString veritabaniKonum;

    QString secilenIsim;

    bool veritabaninaBaglan();
    void veritabanindanAyril();
    void veritabaniYenile();
};

#endif // MAINWINDOW_H
