#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <math.h>
#include <QtDebug>

//manjeo de los enemigos
class enemigos: public QGraphicsPixmapItem
{
public:
    //constructor
    enemigos();

    //metodos de la clase
    void mover(int px, int py);

    //metodos set y get
    void setVel(double nvx);
    double getVel();

private:
    //atributos
    double vel=0.3;
};

#endif // ENEMIGOS_H
