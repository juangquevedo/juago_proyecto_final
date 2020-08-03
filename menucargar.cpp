#include "menucargar.h"
#include "ui_menucargar.h"

menucargar::menucargar(int jugadores, int nivel, vector<int> &vidas,vector<float> &posxs,vector<float> &posys,vector<int> &skins,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menucargar)
{
    ui->setupUi(this);
    level1= new Nivel_1(jugadores, nivel, vidas,posxs,posys,skins);
    level1->show();
    this->close();
}

menucargar::~menucargar()
{
    delete ui;
    delete level1;
}
