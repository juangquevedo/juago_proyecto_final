#include "antibacterias.h"
#include <math.h>

extern Nivel_1* nivel1; // Objeto global externo llamado game
antibacterias::antibacterias(QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent)
{
    //Graficar la bala
    setPixmap(QPixmap(":/Imagenes/defensa.PNG"));

    //Conectar el movimiento de la bala
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    timer->start(10);
}

antibacterias::~antibacterias()
{
    delete timer;
}

//void direcciones(float x, float y, float velx, float vely)
// {
//      sx = x; sy = y; vx = velx; vy = vely;
// }
