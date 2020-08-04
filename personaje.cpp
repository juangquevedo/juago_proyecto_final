#include "personaje.h"
#include "nivel_1.h"

personaje::personaje(){
    setPixmap(QPixmap(":/Imagenes/skin_1.png").scaled(25,40));
}

void personaje::setSkin(int skin){
    skinval=skin;
    //Estas son las apariencias que puede tener el personaje
    switch (skin){
    case 1:       
        setPixmap(QPixmap(":/Imagenes/skin_1.png").scaled(25,40));
        break;
    case 2:

        setPixmap(QPixmap(":/Imagenes/skin_2.png").scaled(25,40));
        break;
    case 3:

        setPixmap(QPixmap(":/Imagenes/skin_3.png").scaled(25,40));
        break;
    default:
        skin=1;
        setPixmap(QPixmap(":/Imagenes/skin_1.png").scaled(25,40));
        break;
    }
}

int personaje::getSkin(){

return skinval;
}

void personaje::mover_personaje(int Fx, int Fy, double cf){
    //Esta función es llamada al mover al personaje y calcula la
    //aceleración que obtiene el personaje dependiendo de la fricción
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

void personaje::actualizar(QList<paredes> Lparedes,int xmap, int ymap){

    //Esta función calcula la fricción de donde se encuentre el personaje
    //y calcula el movimiento del personaje, no permite que se salga del mapa
    double x=(this->x()),y=(this->y());
    Vx=Ax*t;
    Vy=Ay*t;
    x+=(Vx*t*1.5)+(0.5*Ax*pow(t,2));
    y+=(Vy*t*1.5)+(0.5*Ay*pow(t,2));
    if(x>0 && x<xmap-25 && !choque(Lparedes,x,this->y()))
        this->setPos(x,this->y());
    if(y>0 && y<ymap-40 && !choque(Lparedes,this->x(),y))
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

bool personaje::choque(QList<paredes> Lparedes,int px,int py){
    QList<paredes>::iterator it=Lparedes.begin();
    for(;it!=Lparedes.end();it++){
        if((*it).contacto(px,py,25,40))
            return 1;
    }
    return 0;
}

void personaje::setVida(int nv){
    vida=nv;
}

void personaje::incrementardefensa()
{
    numdefen++;
}
void personaje::rotacion(qreal x, qreal y)
{
   setTransformOriginPoint(20, 20);
   qreal deg = atan2(y, x)*180/3.14159;
   //setRotation(deg+90);
    rotaciondeg = deg+90;
}
int personaje::getVida(){
    return vida;
}
void personaje::parar(){
    Ax=0;
    Ay=0;
}

qreal personaje::getRotation()
{
return rotaciondeg;

}
