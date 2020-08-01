#ifndef PAREDES_H
#define PAREDES_H


class paredes{
public:
    paredes(int x_par,int y_par,int an_par,int al_par);
    bool contacto(int x_obj,int y_obj,int an_obj,int al_obj);
    int x,y,ancho,alto;
};

#endif // PAREDES_H
