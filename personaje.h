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
    int getSkin();
    //movimiento del personaje
    void mover_personaje(int Fx,int Fy,double cf);
    void actualizar(int xmap, int ymap);
    //funciones get y set
    void setVida(int nv);
    int getVida();
    void incrementardefensa();
     void rotacion(int x, int y);
    qreal getRotation();

private:
    //estas son las caracteristicas del personaje
    double t=0.03;
    double Vx=0,Vy=0;
    double Ax=0,Ay=0;
    double fric;
    double masa=75;
    int vida=100;
    int skinval=0;
    int numdefen;
    qreal rotaciondeg;
};

#endif // PERSONAJE_H
