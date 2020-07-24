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

void personaje::mover_personaje(int Fx, int Fy, int cf){
    float p=masa*9.8;;
    fric=cf*p;
    Fx=(p*Fx);
    Fy=(p*Fy);
    Ax+=(Fx-fric)/masa;
    Ay+=(Fy-fric)/masa;
}

void personaje::actualizar(){
    double x=(this->x()),y=(this->y());
    Vx+=Ax;
    Vy+=Ay;
    x+=Vx+(0.5*Ax);
    y+=Vy+(0.5*Ay);
    setPos(x,y);
}













