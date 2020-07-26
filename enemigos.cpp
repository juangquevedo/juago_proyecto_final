#include "enemigos.h"

enemigos::enemigos(){
    //inicio de la imagen del enemigo
    setPixmap(QPixmap(":/new/prefix1/Imagenes/virus.png").scaled(30,30));
}

void enemigos::mover(int px, int py){
    //en esta funcion el emenigo calcula a el como moverse para seguir el enemigo,
    //esto usando las formulas de gravedad de la practica 6
    double r,ax,ay,x,y;
    r=sqrt(pow(px-this->x(),2)+pow(py-this->y(),2));
    ax=(100/pow(abs(r),3))*(px-this->x());
    ay=(100/pow(abs(r),3))*(py-this->y());
    if(ax>=0) x=ax+vel;
    else x=ax-vel;
    if(ay>=0) y=ay+vel;
    else y=ay-vel;
    if((ax+vel)>0.5) ax=0.5;
    if((ax+vel)<-0.5) ax=-0.5;
    if((ay+vel)>0.5) ay=1;
    if((ay+vel)<-0.5) ay=-0.5;
    if(r<23) setPos(this->x(),this->y()); //r<23 (this->x(),this->y())
    else setPos(this->x()+x,this->y()+y);
}

void enemigos::setVel(double nvx){
    vel=nvx;
}

double enemigos::getVel(){
    return vel;
}
