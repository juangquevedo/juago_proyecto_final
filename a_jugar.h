#ifndef A_JUGAR_H
#define A_JUGAR_H
#include "menu.h"
#include "menu_2_jugadores.h"

//Librerías
#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QTimer>
#include <iostream>

namespace Ui {
class a_jugar;
}

class a_jugar : public QMainWindow
{
    Q_OBJECT

public:
    explicit a_jugar(QWidget *parent = nullptr);
    ~a_jugar();
    void ocultar();
    void control();
//private slots:
//    void on_Individual_clicked();
//    void on_Multijugador_clicked();
//    void on_Cargar_clicked();

private slots:
    void on_un_jugador_clicked();

    void on_dos_jugadores_clicked();


private:
    Ui::a_jugar *ui;
    Menu* menu1;
    menu_2_jugadores* menu2;
    QString name="";
};

#endif // A_JUGAR_H
