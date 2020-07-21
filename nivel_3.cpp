#include "nivel_3.h"
#include "ui_nivel_3.h"

Nivel_3::Nivel_3(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_3){
    ui->setupUi(this);
}

Nivel_3::~Nivel_3(){
    delete ui;
}
