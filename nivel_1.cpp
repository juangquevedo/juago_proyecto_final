#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);

    //inicio de la escena y la vista
    scene= new QGraphicsScene(this);
    view= new QGraphicsView(this);
    scene->setSceneRect(0,0,xmap,ymap);
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Imagenes/mapa pokemon.jpg").scaled(2560,1280)));
    view->setScene(scene);
    view->resize(800,600);
    this->resize(800,600);

    //inicio del personaje
    jugadores=1;
    player= new personaje;
    player->setPos(750,750);
    scene->addItem(player);
    view->centerOn(player->x(),player->y());

    //timmers
    time_personje= new QTimer;
    time_items= new QTimer;

    time_personje->stop();
    time_items->stop();

    connect(time_personje,SIGNAL(timeout()),this,SLOT(act_per()));
    connect(time_items,SIGNAL(timeout()),this,SLOT(act_items()));

    //inicio de la barra de vida
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
    if(jugadores==2) delete player_2;
}

void Nivel_1::nivel_2(){
    player->setPos(10,10);
    xmap=1182;
    ymap=321;
    scene->setSceneRect(0,0,xmap,ymap);
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Imagenes/mapa edificio.png").scaled(xmap,ymap)));
    enemi+=5;
}

void Nivel_1::keyPressEvent(QKeyEvent *event){
    if(jugadores==1){
        if(event->key() == Qt::Key_W)
            player->mover_personaje(0,-1,fric);

        if(event->key() == Qt::Key_S)
            player->mover_personaje(0,1,fric);

        if(event->key() == Qt::Key_A)
            player->mover_personaje(-1,0,fric);

        if(event->key() == Qt::Key_D)
            player->mover_personaje(1,0,fric);
    }
    else{
        if(event->key() == Qt::Key_W)
            player->mover_personaje(0,-1,fric);

        if(event->key() == Qt::Key_S)
            player->mover_personaje(0,1,fric);

        if(event->key() == Qt::Key_A)
            player->mover_personaje(-1,0,fric);

        if(event->key() == Qt::Key_D)
            player->mover_personaje(1,0,fric);

        if(event->key() == Qt::Key_I)
            player_2->mover_personaje(0,-1,fric);

        if(event->key() == Qt::Key_K)
            player_2->mover_personaje(0,1,fric);

        if(event->key() == Qt::Key_J)
            player_2->mover_personaje(-1,0,fric);

        if(event->key() == Qt::Key_L)
            player_2->mover_personaje(1,0,fric);
    }
}

void Nivel_1::dos_jugadores(int skin_2){
    jugadores=2;
    player_2= new personaje;
    player_2->setSkin(skin_2);
    scene->addItem(player_2);
    player_2->setPos(780,750);

    barra_p2= new QGraphicsPixmapItem;
    barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
    scene->addItem(barra_p2);
    barra_p2->setPos(player->x()-250,player->y()-270);

    enemi*=2;
    //inicio de enemigos
    crear_enemigos();
    crear_items();
    time_personje->start(10);
    time_items->start(10);
}

void Nivel_1::setskin(int skin){
    //esta funcion la llama el menu para seleccionar la apariencia del personaje
    player->setSkin(skin);
    //inicio de enemigos
    crear_enemigos();
    crear_items();
    time_personje->start(10);
    time_items->start(10);
}

void Nivel_1::crear_enemigos(){
    //se crean enemigos en una posicion aleatoria
    srand(time(NULL));
    for(int i=0;i<enemi;i++){
        enemys.push_back(new enemigos);
        enemys.back()->setPos(10+rand()%(xmap-9),10+rand()%(ymap-9));
        scene->addItem(enemys.back());
    }
}

void Nivel_1::crear_items(){
    //se crean los items de cura
    srand(time(NULL));
    for(int i=0;i<enemi/2;i++){
        itemss.push_back(new items);
        itemss.back()->setPos(10+rand()%(xmap-9),10+rand()%(ymap-9));
        scene->addItem(itemss.back());
    }
}

void Nivel_1::act_per(){
    //esta funcion actualiza al personaje y a los enemigos
    int dx=player->x(),dy=player->y();
    QList <enemigos *>::iterator it=enemys.begin();
    player->actualizar();
    if(jugadores==2){
        player_2->actualizar();
        dx=(abs(player->x())+abs(player_2->x()))/2;
        dy=(abs(player->y())+abs(player_2->y()))/2;
    }
    //actualizo la vista y la barra de vida para que enfoquen al jugador o los jugadores
    view->centerOn(dx,dy);
    if((dx>380 && dx<xmap-380)){
        barra->setPos(dx-250,barra->y());
        if(jugadores==2) barra_p2->setPos(dx-250,barra->y());
    }
    if(dy>280 && dy<ymap-280){
        barra->setPos(barra->x(),dy+260);
        if(jugadores==2) barra_p2->setPos(barra->x(),dy-260);
    }

    //en este ciclo se maneja el movimiento de los enemigos    
    if(jugadores==2){
        for(;it!=enemys.end();it++){
            if((abs(dx-(*it)->x()))<400 && (abs(dy-(*it)->y()))<300){
                dx=sqrt(pow(player->x()+12-(*it)->x(),2)+pow(player->y()+20-(*it)->y(),2));
                dy=sqrt(pow(player_2->x()+12-(*it)->x(),2)+pow(player_2->y()+20-(*it)->y(),2));
                if(dx>dy)
                    (*it)->mover(player_2->x(),player_2->y());
                else
                    (*it)->mover(player->x(),player->y());
                if(dy<30){
                    player_2->setVida(player_2->getVida()-10);
                    scene->removeItem((*it));
                    (*it)->setPos(10000,10000);}
                if(dx<30){
                    player->setVida(player->getVida()-10);
                    scene->removeItem((*it));
                    (*it)->setPos(10000,10000);}
                act_barra();
            }
        }
    }
    else{
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
    }

}

void Nivel_1::act_items(){
    QList <items *>::iterator it=itemss.begin();
    for(;it!=itemss.end();it++){
        if((*it)->toque(player->x(),player->y()) && player->getVida()<100){
            player->setVida(player->getVida()+(*it)->getcura());
            (*it)->setPos(-10000,-10000);
        }
        if(jugadores==2){
            if((*it)->toque(player_2->x(),player_2->y()) && player_2->getVida()<100){
                player->setVida(player_2->getVida()+(*it)->getcura());
                (*it)->setPos(-10000,-10000);
            }
        }
        act_barra();
    }

    //este if es el que le avisa al programa que el jugador se ha quedado sin vida
    if(player->getVida()<=0 && !dead){
        QMessageBox mensaje;
        mensaje.setText("Perdiste judor 1");
        mensaje.exec();
        scene->removeItem(player);
        player->setPos(20000,20000);
        dead=1;
    }
    if(jugadores==2){
        if(player_2->getVida()<=0){
            QMessageBox mensaje;
            mensaje.setText("Perdiste jugador 2");
            mensaje.exec();
            scene->removeItem(player);
            player_2->setPos(20000,20000);
        }
    }
}

void Nivel_1::act_barra(){
    //esta funcion cambia la imagen de la barra de vida dependiendo de la salud del personaje
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
    //aqui se controla la barra del segundo jugador
    if(jugadores==2){
        if(player_2->getVida()>=100)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
        else if(player_2->getVida()>=90 && player_2->getVida()<100)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 90%.png").scaled(500,20));
        else if(player_2->getVida()>=80 && player_2->getVida()<90)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 80%.png").scaled(500,20));
        else if(player_2->getVida()>=70 && player_2->getVida()<80)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 70%.png").scaled(500,20));
        else if(player_2->getVida()>=60 && player_2->getVida()<70)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 60%.png").scaled(500,20));
        else if(player_2->getVida()>=50 && player_2->getVida()<60)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 50%.png").scaled(500,20));
        else if(player_2->getVida()>=40 && player_2->getVida()<50)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 40%.png").scaled(500,20));
        else if(player_2->getVida()>=30 && player_2->getVida()<40)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 30%.png").scaled(500,20));
        else if(player_2->getVida()>=20 && player_2->getVida()<30)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 20%.png").scaled(500,20));
        else if(player_2->getVida()>=10 && player_2->getVida()<20)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 10%.png").scaled(500,20));
        else if(player_2->getVida()>=0 && player_2->getVida()<10)
            barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 0%.png").scaled(500,20));
    }
}
