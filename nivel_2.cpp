#include "nivel_2.h"
#include "ui_nivel_2.h"

Nivel_2::Nivel_2(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_2){
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png"));/*
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_2.png"));
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_3.png"));*/
}

Nivel_2::~Nivel_2(){
    delete ui;
}


