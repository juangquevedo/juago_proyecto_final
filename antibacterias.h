#ifndef ANTIBACTERIAS_H
#define ANTIBACTERIAS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
#include <math.h>
#include "enemigos.h"
#include "nivel_1.h"

class antibacterias: public QObject, public QGraphicsPixmapItem
{    Q_OBJECT
public:
     //Constructor, Destructor
    antibacterias(QGraphicsItem* parent= nullptr);
    ~antibacterias();
     //Metodos publicos
//     void direcciones(float x, float y, float velx, float vely);
//     void colisiones();

     //Atributos publicos
     QTimer* timer;
public slots:
//     void moveBullet();
 private:
     //Nivel_1 *nivel1;
//     float sx;
//     float sy;
//     float vy;
//     float vx;
};

#endif // ANTIBACTERIAS_H
