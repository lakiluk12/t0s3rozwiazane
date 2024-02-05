#ifndef ZAWODNICY_H
#define ZAWODNICY_H

#include <QDialog>
#include "zawodnik.h"
namespace Ui {
class zawodnicy;
}

class zawodnicy : public QDialog
{
    Q_OBJECT

public:
    explicit zawodnicy(QWidget *parent = nullptr);
    ~zawodnicy();
    QString GetNazwisko() const;
    int GetWiek() const;
    int GetPkt() const;
private:
    Ui::zawodnicy *ui;
    zawodnik nowy;
};

#endif // ZAWODNICY_H
