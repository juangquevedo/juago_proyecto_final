#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    void setSkin(int skin);
    void mover_personaje(int Fx,int Fy,int cf);
    void actualizar();
    //void cal_vel(int velx,int vely);
private:
    double Vx=0,Vy=0;
    double Ax=0,Ay=0;
    double fric;
    double masa=75;
};

#endif // PERSONAJE_H
