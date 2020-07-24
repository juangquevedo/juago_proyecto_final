#include "enemigos.h"

enemigos::enemigos(){
    setPixmap(QPixmap(":/new/prefix1/Imagenes/virus.png").scaled(30,30));
}

void enemigos::mover(int px, int py){
    double r,ax,ay;
    r=sqrt(pow(px-this->x(),2)+pow(py-this->y(),2));
    ax=(750/pow(abs(r),3))*(px-this->x());
    ay=(750/pow(abs(r),3))*(py-this->y());
    setPos(this->x()+ax,this->y()+ay);
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
