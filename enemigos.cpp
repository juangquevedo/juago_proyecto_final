#include "enemigos.h"

enemigos::enemigos(){
    setPixmap(QPixmap(":/new/prefix1/Imagenes/virus.png").scaled(30,30));
}

void enemigos::setVelx(double nvx){
    vx=nvx;
}

void enemigos::setVely(double nvy){
    vy=nvy;
}

double enemigos::getVelx(){
    return vx;
}

double enemigos::getVely(){
    return vy;
}
