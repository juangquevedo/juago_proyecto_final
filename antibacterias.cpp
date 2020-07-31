#include "antibacterias.h"
#include <math.h>

//extern Nivel_1* nivel1; // Objeto global externo llamado nivel1
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

//void antibacterias::colisiones()
//{
//    //Destruir el enemigo o colisionar con muro
//    QList<QGraphicsItem*> colision_items = collidingItems();
//    for(int i = 0, n = colision_items.size(); i<n; ++i){
//        if(typeid(colision_items[i]) == typeid(enemigos)){
//            //Resto el numero de enemigos
//            //nivel1->decrementarenemigos();

//            //Remover
//            scene()->removeItem(colision_items[i]);
//            scene()->removeItem(this);

//            //Eliminar de memoria
//            delete colision_items[i];
//            delete this;

//            return;
//        }
//    }
//}
//void antibacterias::direcciones(float x, float y, float velx, float vely)
// {
//      sx = x;
//      sy = y;
//      vx = velx;
//      vy = vely;
// }
//void antibacterias::moveBullet()
//{
//    colisiones();

//    sx += vx*0.02;
//    sy += vy*0.02;
//    setPos(sx, sy);

//    if(sx < 0 || sx > 1000 || sy < 0 || sy > 600){
//        delete this;
//    }
//}
