#include "nivel_2.h"
#include "ui_nivel_2.h"

Nivel_2::Nivel_2(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_2){
    ui->setupUi(this);
    scene->setSceneRect(0,0,2000,2000);
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);
}

Nivel_2::~Nivel_2(){
    delete ui;
}


