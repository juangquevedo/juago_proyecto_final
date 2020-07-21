#include "nivel_3.h"
#include "ui_nivel_3.h"

Nivel_3::Nivel_3(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_3){
    ui->setupUi(this);
    scene->setSceneRect(0,0,2000,2000);
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);
}

Nivel_3::~Nivel_3(){
    delete ui;
}
