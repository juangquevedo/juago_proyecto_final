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
