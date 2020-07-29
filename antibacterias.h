#ifndef ANTIBACTERIAS_H
#define ANTIBACTERIAS_H
#include "nivel_1.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <math.h>

class antibacterias: public QObject, public QGraphicsPixmapItem
{    Q_OBJECT
public:
     //Constructor, Destructor
    antibacterias(QGraphicsItem* parent= nullptr);
    ~antibacterias();
     //Metodos publicos
//     void direcciones(float x, float y, float velx, float vely);
     void colisiones();

     //Atributos publicos
     QTimer* timer;
//public slots:
//     void moveBullet();
 private:
//     float sx;
//     float sy;
//     float vy;
//     float vx;
};

#endif // ANTIBACTERIAS_H
