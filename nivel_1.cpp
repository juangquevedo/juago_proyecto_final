#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png"));/*
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_2.png"));
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_3.png"));*/

    scene= new QGraphicsScene(this);
}

Nivel_1::~Nivel_1(){
    delete ui;
}

