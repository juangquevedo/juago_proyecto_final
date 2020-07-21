#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);
    scene= new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);
    player= new personaje;
}

Nivel_1::~Nivel_1(){
    delete ui;
    delete player;
}

void Nivel_1::setskin(int skin){
    player->setSkin(skin);
    player->setPos(10,10);
    scene->addItem(player);
}

