#include "personaje.h"

personaje::personaje(){
    setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png").scaled(25,40));
}

void personaje::setSkin(int skin){
    switch (skin){
    case 1:
        setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png").scaled(25,40));
        break;
    case 2:
        setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_2.png").scaled(25,40));
        break;
    case 3:
        setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_3.png").scaled(25,40));
        break;
    default:
        setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png").scaled(25,40));
        break;
    }
}

void personaje::mover_personaje(int Fx, int Fy, double cf){
    double p=masa*9.8;
    fric=cf*p;
    if(Fx!=0){
        Ax=((Fx*p)+fric)/masa;
    }
    if(Fy!=0){
        Ay=((Fy*p)+fric)/masa;
    }
}

void personaje::actualizar(){
    double x=(this->x()),y=(this->y());
    Vx+=Ax*t;
    Vy+=Ay*t;
    x+=(Vx*t)+(0.5*Ax*pow(t,2));
    y+=(Vy*t)+(0.5*Ay*pow(t,2));
    this->setPos(x,y);
    Ax+=fric/masa;
    Ay+=fric/masa;
    if(Vx<0){
        Vx=0;
        Ax=0;}
    if(Vy<0){
        Vy=0;
        Ay=0;}
}

void personaje::setVida(int nv){
    vida=nv;
}

int personaje::getVida(){
    return vida;
}












