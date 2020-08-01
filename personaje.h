#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>
#include <QtDebug>
#include "paredes.h"


class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    void setSkin(int skin);    //apariencia del personaje
    int getSkin();             //obtener valor del Skin
    void mover_personaje(int Fx,int Fy,double cf);//movimiento del personaje
    void actualizar(QList<paredes> Lparedes,int xmap, int ymap);
    bool choque(QList<paredes> Lparedes, int px, int py);
    void setVida(int nv); //función para configurar vida
    int getVida();        //Retornar vida
    void parar();         //Pausar el personaje
    void incrementardefensa();
    void rotacion(int x, int y);
    qreal getRotation();

private:
    //Estas son las caracteristicas del personaje
    double t=0.05;
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
