#include "items.h"

items::items(){

    setPixmap(QPixmap(":/Imagenes/anti-bacterial.png").scaled(20,20));

}

void items::setcura(int c){
    cura=c;
}

int items::getcura(){
    return cura;
}

bool items::toque(int px, int py){
    bool temp;
    for(int i=this->y();i<this->y()+20;i++){
        temp=(i>=py && i<=(py+40));
        for(int j=this->x();j<(this->x()+20);j++){
            if(temp && j>=px && j<=(px+25))
                return 1;
        }
    }
    return 0;
}











