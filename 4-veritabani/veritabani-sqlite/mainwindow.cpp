#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    if(this->veritabaninaBaglan()){
        qDebug() << "Veritabanina aktif.";
    }
    else{
        qDebug() << "Veritabani hatasi.";
    }

    veritabaniYenile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::veritabaninaBaglan()
{
    veritabaniKonum = "..\\test.db";

    veritabani = QSqlDatabase::addDatabase("QSQLITE");
    veritabani.setDatabaseName(veritabaniKonum);

    if(veritabani.open()){
        qDebug() << "Veritabanina baglanildi!";
        return true;
    }
    else{
        qDebug() << "Veritabanina baglanilamadi!";
        veritabanindanAyril();
        return false;
    }
}

void MainWindow::veritabanindanAyril()
{
    veritabani.close();
    veritabani.removeDatabase(QSqlDatabase::defaultConnection);
}

void MainWindow::veritabaniYenile()
{
    QSqlQuery *qry = new QSqlQuery;

    qDebug() << "Veritabani yenile:" << qry->exec("SELECT * FROM kisiler");

    QSqlQueryModel *kisiler_model = new QSqlQueryModel;

    kisiler_model->setQuery(*qry);

    ui->tableView->setModel(kisiler_model);
}

void MainWindow::on_buton_ekle_clicked()
{
    QSqlQuery qry_ekle;
    QString isimTemp = ui->line_isim->text();
    QString soyisimTemp = ui->line_soyisim->text();
    QString yasTemp = ui->line_yas->text();

    qDebug() << "Ekle:" << qry_ekle.exec("INSERT INTO kisiler(isim, soyisim, yas) VALUES('"+isimTemp+"', '"+soyisimTemp+"', '"+yasTemp+"')");

    veritabaniYenile();
}

void MainWindow::on_tableView_pressed(const QModelIndex &index)
{
    secilenIsim = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    qDebug() << "Secilen isim:" << secilenIsim;
}

void MainWindow::on_buton_duzenle_clicked()
{
    QSqlQuery qry_duzenle;
    QString yasTemp = ui->line_yas->text();
    qry_duzenle.exec("UPDATE kisiler SET yas= '"+yasTemp+"' WHERE isim='"+secilenIsim+"'");
    veritabaniYenile();
}

void MainWindow::on_buton_sil_clicked()
{
    QSqlQuery qry_sil;
    qry_sil.exec("DELETE FROM kisiler WHERE isim='"+secilenIsim+"'");
    veritabaniYenile();
}
