#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>
#include <QtDebug>

class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    void setSkin(int skin);
    //movimiento del personaje
    void mover_personaje(int Fx,int Fy,double cf);
    void actualizar(int xmap, int ymap);
    //funciones get y set
    void setVida(int nv);
    int getVida();
private:
    //estas son las caracteristicas del personaje
    double t=0.03;
    double Vx=0,Vy=0;
    double Ax=0,Ay=0;
    double fric;
    double masa=75;
    int vida=100;
};

#endif // PERSONAJE_H
