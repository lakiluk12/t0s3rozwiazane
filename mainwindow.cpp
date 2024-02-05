#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QPixmap logo;
    logo.load("../t0s3/logo.png");
    ui->logo->setPixmap(logo.scaled(100,100,Qt::KeepAspectRatio));
    ui->zawodnik1->setVisible(false);
    ui->zawodnik2->setVisible(false);
    ui->zawodnik3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool kto_ma_wiecej_pkt(zawodnik jeden, zawodnik dwa){
    return jeden.ilosc_pkt > dwa.ilosc_pkt;
}

void MainWindow::on_dodaj_clicked()
{
    m_okienko = new zawodnicy(nullptr);
    int result = m_okienko->exec();
    if(result){
        zawodnik nowy;
        nowy.nazwisko = m_okienko->GetNazwisko();
        nowy.wiek = m_okienko->GetWiek();
        nowy.ilosc_pkt = m_okienko->GetPkt();
        lista_zawodnikow.push_front(nowy);
    }
    delete m_okienko;

    QAbstractItemModel* const tmp = ui->tableWidget->model();
    while (tmp->rowCount() > 0)
    {
        tmp->removeRow(0);
    }

    std::sort(lista_zawodnikow.begin(), lista_zawodnikow.end(), kto_ma_wiecej_pkt);

    for(int i=0; i < lista_zawodnikow.size(); i++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(lista_zawodnikow[i].nazwisko));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::number(lista_zawodnikow[i].wiek)));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::number(lista_zawodnikow[i].ilosc_pkt)));
    }
}


void MainWindow::on_wyniki_clicked()
{
    if(lista_zawodnikow.size()>0){
    ui->zawodnik1->setVisible(true);
    ui->zawodnik1->setText(lista_zawodnikow[0].nazwisko);
        if(lista_zawodnikow.size()>1){
            ui->zawodnik2->setVisible(true);
            ui->zawodnik2->setText(lista_zawodnikow[1].nazwisko);
                if(lista_zawodnikow.size()>2){
                    ui->zawodnik3->setVisible(true);
                    ui->zawodnik3->setText(lista_zawodnikow[2].nazwisko);
                }
        }
    }


}

