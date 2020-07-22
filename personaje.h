#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    void setSkin(int skin);
    //void calvelocidad();
private:
    //int posx;
    //int posy;
    //double Vx,Vy;
    //double Ax,Ay;
};

#endif // PERSONAJE_H
