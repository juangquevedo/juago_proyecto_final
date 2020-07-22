#include "nivel_3.h"
#include "ui_nivel_3.h"

Nivel_3::Nivel_3(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_3){
    ui->setupUi(this);
    scene= new QGraphicsScene(this);
    view= new QGraphicsView(this);
    scene->setSceneRect(0,0,2000,2000);
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);
    player= new personaje;
    player->setPos(10,10);
    scene->addItem(player);
}

Nivel_3::~Nivel_3(){
    delete ui;
}

void Nivel_3::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        player->setPos(player->x(),player->y()-10);
        view->centerOn(player->x(),player->y());
    }
    if(event->key() == Qt::Key_S){
        player->setPos(player->x(),player->y()+10);
        view->centerOn(player->x(),player->y());
    }
    if(event->key() == Qt::Key_A){
        player->setPos(player->x()-10,player->y());
        view->centerOn(player->x(),player->y());
    }
    if(event->key() == Qt::Key_D){
        player->setPos(player->x()+10,player->y());
        view->centerOn(player->x(),player->y());
    }
}

void Nivel_3::setskin(int skin){
    player->setSkin(skin);
}
