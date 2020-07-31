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
#include <QPushButton>
#include <QMouseEvent>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <enemigos.h>
#include <items.h>
#include "personaje.h"
#include "antibacterias.h"
using namespace std;
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
    void nivel_3();
    void keyPressEvent(QKeyEvent * event);
    void dos_jugadores(int skin_2);
    void setskin(int skin);
    void crear_enemigos();
    void crear_items();
    void act_barra();
    //void decrementarenemigos();
    //int realAngle(int vx_, int vy_);
    //int numEnemigos;

    //bool cargar();
    void guardar();
    //Eventos
//    void mousePressEvent(QMouseEvent* event);
   // void mouseMoveEvent(QMouseEvent* event);

    QString int2str(int long a);

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
    int xvi=800,yvi=600;
    double fric=0.5;
    bool dead=0;
    QString nombre;
};

#endif // NIVEL_1_H
