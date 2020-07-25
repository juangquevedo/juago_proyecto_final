#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);

    //inicio de la escena y la vista
    scene= new QGraphicsScene(this);
    view= new QGraphicsView(this);
    scene->setSceneRect(0,0,2000,2000);
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

    barra= new QGraphicsPixmapItem;
    barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
    scene->addItem(barra);
    barra->setPos(player->x()-250,player->y()+270);
}

Nivel_1::~Nivel_1(){
    delete ui;
    delete scene;
    delete view;
    delete time_personje;
    delete player;
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
    srand(time(NULL));
    for(int i=0;i<(3+rand()%(7-3));i++){
        enemys.push_back(new enemigos);
        enemys.back()->setPos(10+rand()%(1991-10),10+rand()%(1991-10));
        scene->addItem(enemys.back());
    }
}

void Nivel_1::act_per(){
    int dx,dy;
    QList <enemigos *>::iterator it=enemys.begin();
    //player->actualizar();

    //actualizo la vista y la barra de vida para que enfoquen al jugador
    view->centerOn(player->x(),player->y());
    if((player->x()>380 && player->x()<1620))
        barra->setPos(player->x()-250,barra->y());
    if(player->y()>280 && player->y()<1720)
        barra->setPos(barra->x(),player->y()+270);

    for(;it!=enemys.end();it++){
        dx=abs(player->x()-(*it)->x());
        dy=abs(player->y()-(*it)->y());
        if(dx<400 && dy<300){
            (*it)->mover(player->x(),player->y());
            dx=sqrt(pow(player->x()+12-(*it)->x(),2)+pow(player->y()+20-(*it)->y(),2));
            if(dx<30){
                player->setVida(player->getVida()-10);
                scene->removeItem((*it));
                (*it)->setPos(10000,10000);
                act_barra();
            }
        }
    }
    if(player->getVida()<=0){
        QMessageBox mensaje;
        mensaje.setText("Perdiste");
        mensaje.exec();
        scene->removeItem(player);
        player->setPos(20000,20000);
    }
}

void Nivel_1::act_barra(){
    if(player->getVida()>=100)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
    else if(player->getVida()>=90 && player->getVida()<100)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 90%.png").scaled(500,20));
    else if(player->getVida()>=80 && player->getVida()<90)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 80%.png").scaled(500,20));
    else if(player->getVida()>=70 && player->getVida()<80)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 70%.png").scaled(500,20));
    else if(player->getVida()>=60 && player->getVida()<70)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 60%.png").scaled(500,20));
    else if(player->getVida()>=50 && player->getVida()<60)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 50%.png").scaled(500,20));
    else if(player->getVida()>=40 && player->getVida()<50)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 40%.png").scaled(500,20));
    else if(player->getVida()>=30 && player->getVida()<40)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 30%.png").scaled(500,20));
    else if(player->getVida()>=20 && player->getVida()<30)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 20%.png").scaled(500,20));
    else if(player->getVida()>=10 && player->getVida()<20)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 10%.png").scaled(500,20));
    else if(player->getVida()>=0 && player->getVida()<10)
        barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 0%.png").scaled(500,20));
}
