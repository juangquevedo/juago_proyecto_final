#include "nivel_3.h"
#include "ui_nivel_3.h"

Nivel_3::Nivel_3(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_3){
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_1.png"));/*
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_2.png"));
    ui->label->setPixmap(QPixmap(":/new/prefix1/Imagenes/skin_3.png"));*/
}

Nivel_3::~Nivel_3(){
    delete ui;
}
