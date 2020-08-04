#include "antibacterias.h"
#include <math.h>
#include "nivel_1.h"

//extern Nivel_1* nivel1; // Objeto global externo llamado nivel1
antibacterias::antibacterias(QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent)
{
    //Graficar la bala
    setPixmap(QPixmap(":/Imagenes/gotacajatransparente.png").scaled(25,40));
//    soundeffects = new QMediaPlayer;
//    soundeffects-> setMedia(QUrl("qrc:/Audios/y2mate.com - Water Splash - Sound Effect_385dsklaW2A.mp3"));
//    soundeffects->setVolume(320);
//    soundeffects->play();
    //Conectar el movimiento de la defensa
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveBullet()));
    timer->start(10);
}

antibacterias::~antibacterias()
{
    delete timer;
}


void antibacterias::direcciones(float x, float y, float velx, float vely)
 {
      sx = x;
      sy = y;
      vx = velx;
      vy = vely;
 }
void antibacterias::moveBullet()
{
    //colisiones();

    sx += vx*0.02;
    sy += vy*0.02;
    setPos(sx, sy);

}

void antibacterias::setnivel(Nivel_1 &n1)
{
    nivel1 = &n1;


}

float antibacterias::getPosx_defensa(){
    return sx;

}

float antibacterias::getPosy_defensa(){
    return sy;

}

