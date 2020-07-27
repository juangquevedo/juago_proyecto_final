#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include <QPixmap>
#include <QDebug>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <personaje.h>
#include <enemigos.h>
#include <items.h>

namespace Ui {
class Nivel_1;
}

class Nivel_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();
    void nivel_2();
    void keyPressEvent(QKeyEvent * event);
    void dos_jugadores(int skin_2);
    void setskin(int skin);
    void crear_enemigos();
    void crear_items();
    void act_barra();

private slots:
    void act_per();
    void act_items();

private:
    Ui::Nivel_1 *ui;
    QGraphicsScene *scene;
    QGraphicsView * view;
    personaje *player,*player_2;
    QList <enemigos *> enemys;
    QList <items *> itemss;
    QTimer *time_personje,*time_items;
    QGraphicsPixmapItem *barra,*barra_p2;
    int jugadores, enemi=10;
    int xmap=2560,ymap=1280;
    double fric=0.5;
    bool dead=0;
};

#endif // NIVEL_1_H
