#include "personaje.h"

personaje::personaje(){
    setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png").scaled(25,40));
}

void personaje::setSkin(int skin){
    //estas son las apariencias que puede tener el personaje
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
    //esta funcion es llamada al mover al personaje y calcula la
    //aceleracion que obtiene el personaje dependiendo de la friccion
    double p=masa*9.8;
    fric=cf*p;
    if(Fx<0)
        Ax=((Fx*p*60)+fric)/masa;
    else if (Fx>0)
        Ax=((Fx*p*60)-fric)/masa;
    if(Fy<0)
        Ay=((Fy*p*60)+fric)/masa;
    if(Fy>0)
        Ay=((Fy*p*60)-fric)/masa;
}

void personaje::actualizar(int xmap, int ymap){
    //esta funcion calcula la friccion de donde se encuentre el personaje
    //y calcula el movimiento del personaje, no permite que se salga del mapa
    double x=(this->x()),y=(this->y());
    Vx=Ax*t;
    Vy=Ay*t;
    x+=(Vx*t*1.5)+(0.5*Ax*pow(t,2));
    y+=(Vy*t*1.5)+(0.5*Ay*pow(t,2));
    if(x>0 && x<xmap-25)
        this->setPos(x,this->y());
    if(y>0 && y<ymap-40)
        this->setPos(this->x(),y);
    if(Ax<0)
        Ax+=fric/masa;
    else if(Ax>0)
        Ax-=fric/masa;
    if(Ay<0)
        Ay+=fric/masa;
    else if(Ay>0)
        Ay-=fric/masa;
}

void personaje::setVida(int nv){
    vida=nv;
}

int personaje::getVida(){
    return vida;
}












