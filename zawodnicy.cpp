#include "zawodnicy.h"
#include "ui_zawodnicy.h"

zawodnicy::zawodnicy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::zawodnicy)
{
    ui->setupUi(this);
}
QString zawodnicy::GetNazwisko() const
{
    return ui->nazwisko->displayText();
}
int zawodnicy::GetWiek() const
{
    return ui->wiek->value();
}
int zawodnicy::GetPkt() const
{
    return ui->liczbpkt->value();
}
zawodnicy::~zawodnicy()
{
    delete ui;
}
