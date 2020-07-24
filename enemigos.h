#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>

//manjeo de los enemigos
class enemigos: public QGraphicsPixmapItem
{
public:
    //constructor
    enemigos();

    //metodos de la clase
    void mover(int px, int py);

    //metodos set y get
    void setVelx(double nvx);
    void setVely(double nvy);
    double getVelx();
    double getVely();

private:
    //atributos
    double vx,vy;
};

#endif // ENEMIGOS_H
