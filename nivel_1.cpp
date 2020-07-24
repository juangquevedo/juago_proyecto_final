#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);

    //inicio de la escena y la vista
    scene= new QGraphicsScene(this);
    view= new QGraphicsView(this);
    scene->setSceneRect(0,0,2000,2000);
    //scene->setBackgroundBrush(QBrush(QImage(":/C:/Users/dbhf/Desktop/FONDO.jpg")));
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Imagenes/mapa_provisional.png").scaled(2000,2000)));
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);

    //inicio del personaje
    player= new personaje;
    player->setPos(1000,1000);
    scene->addItem(player);
    view->centerOn(player->x(),player->y());

    //inicio de enemigos
    crear_enemigos();

    //timmers
    time_personje= new QTimer;

    time_personje->stop();

    connect(time_personje,SIGNAL(timeout()),this,SLOT(act_per()));

    time_personje->start(10);

}

Nivel_1::~Nivel_1(){
    delete ui;
    delete player;
    delete time_personje;
}

void Nivel_1::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W)
        player->setPos(player->x(),player->y()-10);

    if(event->key() == Qt::Key_S)
        player->setPos(player->x(),player->y()+10);

    if(event->key() == Qt::Key_A)
        player->setPos(player->x()-10,player->y());

    if(event->key() == Qt::Key_D)
        player->setPos(player->x()+10,player->y());
        //player->mover_personaje(1,0,-0.5);

}

void Nivel_1::setskin(int skin){
    player->setSkin(skin);
}

void Nivel_1::crear_enemigos(){
    /*srand(time(NULL));
    for(int i=0;i<(3+rand()%(7-3));i++){
        enemys.push_back(new enemigos);
        enemys.back()->setPos(10+rand()%(1991-10),10+rand()%(1991-10));
        scene->addItem(enemys.back());
    }*/
    enemys.push_back(new enemigos);
    enemys.back()->setPos(1300,1000);
    scene->addItem(enemys.back());
}

void Nivel_1::act_per(){
    QList <enemigos *>::iterator it=enemys.begin();
    //player->actualizar();
    //view->centerOn(player->x(),player->y());
    for(;it!=enemys.end();it++){
        (*it)->mover(player->x(),player->y());
    }
}

