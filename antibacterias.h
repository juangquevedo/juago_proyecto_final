#ifndef ANTIBACTERIAS_H
#define ANTIBACTERIAS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QMediaPlayer>
#include <math.h>
#include "enemigos.h"
using namespace std;
class Nivel_1;
class antibacterias: public QObject, public QGraphicsPixmapItem
{    Q_OBJECT
public:
     //Constructor, Destructor
    antibacterias(QGraphicsItem* parent= nullptr);
    ~antibacterias();
     //Metodos publicos
     void setnivel(Nivel_1& n1);
     void direcciones(float x, float y, float velx, float vely);
     float getPosx_defensa();
     float getPosy_defensa();
     //Atributos publicos
     QTimer* timer;
public slots:
     void moveBullet();
 private:
     Nivel_1* nivel1;
     QMediaPlayer* soundeffects;
     float sx;
     float sy;
     float vy;
     float vx;
};

#endif // ANTIBACTERIAS_H
