#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zawodnicy.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dodaj_clicked();

    void on_wyniki_clicked();

private:
    QList<zawodnik> lista_zawodnikow;
    Ui::MainWindow *ui;
    zawodnicy *m_okienko;
};
#endif // MAINWINDOW_H
