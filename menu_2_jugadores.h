#ifndef MENU_2_JUGADORES_H
#define MENU_2_JUGADORES_H

#include <QMainWindow>
#include <QPixmap>

#include "nivel_1.h"

namespace Ui {
class menu_2_jugadores;
}

class menu_2_jugadores : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu_2_jugadores(QWidget *parent = nullptr);
    ~menu_2_jugadores();

private slots:
    void on_but_ski_1_play_1_clicked();

    void on_but_ski_2_play_1_clicked();

    void on_but_ski_3_play_1_clicked();

    void on_but_ski_1_play_2_clicked();

    void on_but_ski_2_play_2_clicked();

    void on_but_ski_3_play_2_clicked();

    void on_bot_nil_1_clicked();

    void on_bot_nil_2_clicked();

    void on_bot_nil_3_clicked();

private:
    Ui::menu_2_jugadores *ui;
    //carga de los niveles
    Nivel_1 *level1;

    //variable para definir la apariencia del personaje
    int skin_1=0,skin_2=0;
};

#endif // MENU_2_JUGADORES_H
