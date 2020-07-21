#include "nivel_2.h"
#include "ui_nivel_2.h"

Nivel_2::Nivel_2(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_2){
    ui->setupUi(this);
}

Nivel_2::~Nivel_2(){
    delete ui;
}


