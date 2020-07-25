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
    void mover_personaje(int Fx,int Fy,double cf);
    void actualizar();
    void setVida(int nv);
    int getVida();
    //void cal_vel(int velx,int vely);
private:
    double t=0.03;
    double Vx=0,Vy=0,vel=5;
    double Ax=0,Ay=0;
    double fric;
    double masa=75;
    int vida=100;
};

#endif // PERSONAJE_H
