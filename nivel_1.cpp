#include "nivel_1.h"
#include "ui_nivel_1.h"

Nivel_1::Nivel_1(QWidget *parent) : QMainWindow(parent),ui(new Ui::Nivel_1){
    ui->setupUi(this);


    //inicio de la escena y la vista
    scene= new QGraphicsScene(this);
    view= new QGraphicsView(this);
    scene->setSceneRect(0,0,xmap,ymap);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/mapa pokemon.jpg").scaled(2560,1280)));
    view->setScene(scene);
    view->resize(xvi,yvi);
    this->resize(xvi,yvi);

    //inicio del personaje
    jugadores=1;
    player= new personaje;
    player->setPos(1960,1106);
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
    barra->setPixmap(QPixmap(":/Imagenes/barra 100%.png").scaled(500,20));
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
    //cambios para que el nivel concuerde con la ecena y suba la dificultad
    player->setPos(20,30);
    xmap=1182;
    ymap=321;
    yvi=ymap;
    fric=0.7;
    view->resize(xvi,yvi+20);
    this->resize(xvi,yvi+20);
    scene->setSceneRect(0,0,xmap,ymap);
    scene->setBackgroundBrush(QBrush(QImage(":/Imagenes/mapa edificio.png").scaled(xmap,ymap)));
    barra->setPos(100,yvi-30);
}

void Nivel_1::nivel_3(){
    //cambios para que el nivel concuerde con la ecena y suba la dificultad
    player->setPos(371,187);
    enemi+=5;
}

void Nivel_1::keyPressEvent(QKeyEvent *event){
    //movimiento para cuando hay 1 jugador
    if(jugadores==1){
        if(event->key() == Qt::Key_W)
            player->mover_personaje(0,-1,fric);
            //player->setPos(player->x(),player->y()-10);

        if(event->key() == Qt::Key_S)
            player->mover_personaje(0,1,fric);
            //player->setPos(player->x(),player->y()+10);

        if(event->key() == Qt::Key_A)
            player->mover_personaje(-1,0,fric);
            //player->setPos(player->x()-10,player->y());

        if(event->key() == Qt::Key_D)
            player->mover_personaje(1,0,fric);
            //player->setPos(player->x()+10,player->y());
    }
    //movimiento para cuando hay 2 jugadores
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
    //essta funcion crea al jugador 2 y su barra de vida
    jugadores=2;
    player_2= new personaje;
    player_2->setSkin(skin_2);
    scene->addItem(player_2);
    player_2->setPos(780,750);

    barra_p2= new QGraphicsPixmapItem;
    barra_p2->setPixmap(QPixmap(":/Imagenes/barra 100%.png").scaled(500,20));
    scene->addItem(barra_p2);
    barra_p2->setPos(player->x()-250,player->y()-270);

    //aumenta los enemigos al doble
    enemi*=2;
    //inicio de enemigos
    crear_enemigos();
    crear_items();
    //inicio los timers ahora para que si se reflejen los cambios del nivel
    time_personje->start(10);
    time_items->start(10);
}
void Nivel_1::setskin(int skin){
    //esta funcion la llama el menu para seleccionar la apariencia del personaje
    player->setSkin(skin);
    //inicio de enemigos e items
    crear_enemigos();
    crear_items();
    //inicio los timers ahora para que si se reflejen los cambios del nivel
    time_personje->start(10);
    time_items->start(10);
}

void Nivel_1::crear_enemigos(){
    //se crean enemigos en una posicion aleatoria
    srand(time(NULL));
    for(int i=0;i<enemi;i++){
        enemys.push_back(new enemigos);
        enemys.back()->setPos(10+rand()%((xmap-30)-9),10+rand()%((ymap-30)-9));
        scene->addItem(enemys.back());
    }
}
void Nivel_1::crear_items(){
    //se crean los items de cura
    srand(time(NULL));
    for(int i=0;i<enemi/2;i++){
        itemss.push_back(new items);
        itemss.back()->setPos(10+rand()%((xmap-20)-9),10+rand()%((ymap-20)-9));
        scene->addItem(itemss.back());
    }
}

void Nivel_1::act_per(){
    //esta funcion actualiza al personaje y a los enemigos
    int dx=player->x(),dy=player->y();
    QList <enemigos *>::iterator it=enemys.begin();
    player->actualizar(xmap,ymap);
    if(jugadores==2){
        player_2->actualizar(xmap,ymap);
        dx=(abs(player->x())+abs(player_2->x()))/2;
        dy=(abs(player->y())+abs(player_2->y()))/2;
    }
    //actualizo la vista y la barra de vida para que enfoquen al jugador o los jugadores
    view->centerOn(dx,dy);
    if((dx>380 && dx<xmap-380)){
        barra->setPos(dx-200,barra->y());
        if(jugadores==2) barra_p2->setPos(dx-(xvi/2),barra->y());
    }
    if(dy>280 && dy<ymap-280){
        barra->setPos(barra->x(),dy+(yvi/2));
        if(jugadores==2) barra_p2->setPos(barra->x(),dy-(yvi/2));
    }

    //en este ciclo se maneja el movimiento de los enemigos cuando son 2 jugadores
    if(jugadores==2){
        for(;it!=enemys.end();it++){
            if((abs(dx-(*it)->x()))<400 && (abs(dy-(*it)->y()))<300){
                dx=sqrt(pow(player->x()+12-(*it)->x(),2)+pow(player->y()+20-(*it)->y(),2));
                dy=sqrt(pow(player_2->x()+12-(*it)->x(),2)+pow(player_2->y()+20-(*it)->y(),2));
                if(dx>dy)
                    (*it)->mover(player_2->x(),player_2->y());
                else
                    (*it)->mover(player->x(),player->y());
                if((*it)->toque(player_2->x(),player_2->y())){
                    player_2->setVida(player_2->getVida()-10);
                    scene->removeItem((*it));
                    (*it)->setPos(10000,10000);}
                if((*it)->toque(player->x(),player->y())){
                    player->setVida(player->getVida()-10);
                    scene->removeItem((*it));
                    (*it)->setPos(10000,10000);}
                act_barra();
            }
        }
    }
    //en este ciclo se maneja el movimiento de los enemigos cuando es un jugador
    else{
        for(;it!=enemys.end();it++){
            dx=abs(player->x()-(*it)->x());
            dy=abs(player->y()-(*it)->y());
            if(dx<400 && dy<300){
                (*it)->mover(player->x(),player->y());
                dx=sqrt(pow(player->x()+12-(*it)->x(),2)+pow(player->y()+20-(*it)->y(),2));
                if((*it)->toque(player->x(),player->y())){
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
    //este ciclo verifica si el jugador ha tocado algun item
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
        mensaje.setText("Perdiste jugador 1");
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
//int Nivel_1::realAngle(int vx_, int vy_)
//{
//    //Indicar el ángulo con el que sale una bala
//    if(vx_ == 0){
//        if(vy_ > 0){
//            return 180;
//        }
//        else{
//            return 0;
//        }
//    }
//    else if(vy_ == 0){
//        if(vx_ > 0){
//            return 90;
//        }
//        else{
//            return -90;
//        }
//    }
//    else{
//        if(vx_ > 0 && vy_ > 0){
//            return 90+(atan2(vy_,vx_))*grados;
//        }
//        else if(vx_ < 0 && vy_ < 0){
//            return 90+((atan2(vy_,vx_))*grados);
//        }
//        else{
//            if(vx_ < 0 && vy_ > 0){
//                return -270+((atan2(vy_,vx_))*grados);
//            }
//            return 90-((atan2(vy_,vx_))*grados)*-1;
//        }
//    }
//}

//bool Nivel_1::cargar()
//{
//    QString info;
//    QString usuario;
//    QString nivel;
//    QString vida;
//    QString puntaje;
//    QFile file("Partidas");                   //Objeto para manejar la lectura del archivo
//    file.open(QIODevice::ReadOnly);           //Abre el archivo en modo lectura
//    info=file.readAll();

//    int n=0;
//    while(n<file.size()){
//        if(info.at(n) != '\n' && info.at(n) != ' '){
//            usuario+=info.at(n);
//        }
//        else{
//            if(usuario == user){
//                nivel = info.at(++n);
//                level = nivel.toInt();
//                n+=2;
//                while(info.at(n) != ' '){
//                    vida+=info.at(n);
//                    n++;
//                }
//                salud->setSalud(vida.toInt());
//                n++;
//                while(info.at(n) != ' ' && info.at(n) != '\n'){
//                    puntaje+=info.at(n);
//                    n++;
//                }
//                score->setScore(puntaje.toInt());
//                return true;
//            }
//            usuario="";
//        }
//        n++;
//    }
//    return false;
//}

//bool Nivel_1::guardar()
//{
//    QString info;
//    QString usuario;
//    QFile file("Partidas");                       //Objeto para manejar la lectura y escritura del archivo
//    file.open(QIODevice::ReadWrite);           //Abre el archivo en modo lectura/escritura
//    info=file.readAll();

//    int n = 0;
//    while(n<file.size()){
//        if(info.at(n) != '\n' && info.at(n) != ' '){
//            usuario+=info.at(n);
//        }
//        else{
//            if(usuario == user){
//                return false;
//            }
//            usuario="";
//        }
//        n++;
//    }

//    QTextStream stream(&file);
//    stream << user << " " << level << " " << salud->getSalud() << " " << score->getScore() << endl;
//    file.close();
//    return true;
//}

//void Game::mousePressEvent(QMouseEvent *event)
//{
//    //Contar balas gastadas
//    player->incrementarBalas();
//    float rotationdeg = player->getRotation();
//    player->shoottimer();

//    //Crear una nueva bala
//    Bala* bala = new Bala();
//    float x1 = player->x()+(cos(rotationdeg*3.1416/180)) + 15;
//    float y1 = player->y()+(sin(rotationdeg*3.1416/180)) + 27;
//    bala->setPos(x1, y1);
//    bala->setDir(x1, y1,(sin(rotationdeg*3.1416/180))*300 , (-cos(rotationdeg*3.1416/180))*300);
//    bala->setRotation(rotationdeg);
//    scene->addItem(bala);
//}

//void Game::mouseMoveEvent(QMouseEvent *event)
//{
//    player->rotate(event->x()+x11 - player->x(), event->y()+y11 - player->y());
//}

void Nivel_1::act_barra(){
    //esta funcion cambia la imagen de la barra de vida dependiendo de la salud del personaje
    if(player->getVida()>=100)
        barra->setPixmap(QPixmap(":/Imagenes/barra 100%.png").scaled(500,20));
    else if(player->getVida()>=90 && player->getVida()<100)
        barra->setPixmap(QPixmap(":/Imagenes/barra 90%.png").scaled(500,20));
    else if(player->getVida()>=80 && player->getVida()<90)
        barra->setPixmap(QPixmap(":/Imagenes/barra 80%.png").scaled(500,20));
    else if(player->getVida()>=70 && player->getVida()<80)
        barra->setPixmap(QPixmap(":/Imagenes/barra 70%.png").scaled(500,20));
    else if(player->getVida()>=60 && player->getVida()<70)
        barra->setPixmap(QPixmap(":/Imagenes/barra 60%.png").scaled(500,20));
    else if(player->getVida()>=50 && player->getVida()<60)
        barra->setPixmap(QPixmap(":/Imagenes/barra 50%.png").scaled(500,20));
    else if(player->getVida()>=40 && player->getVida()<50)
        barra->setPixmap(QPixmap(":/Imagenes/barra 40%.png").scaled(500,20));
    else if(player->getVida()>=30 && player->getVida()<40)
        barra->setPixmap(QPixmap(":/Imagenes/barra 30%.png").scaled(500,20));
    else if(player->getVida()>=20 && player->getVida()<30)
        barra->setPixmap(QPixmap(":/Imagenes/barra 20%.png").scaled(500,20));
    else if(player->getVida()>=10 && player->getVida()<20)
        barra->setPixmap(QPixmap(":/Imagenes/barra 10%.png").scaled(500,20));
    else if(player->getVida()>=0 && player->getVida()<10)
        barra->setPixmap(QPixmap(":/Imagenes/barra 0%.png").scaled(500,20));

    //aqui se controla la barra del segundo jugador
    if(jugadores==2){
        if(player_2->getVida()>=100)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 100%.png").scaled(500,20));
        else if(player_2->getVida()>=90 && player_2->getVida()<100)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 90%.png").scaled(500,20));
        else if(player_2->getVida()>=80 && player_2->getVida()<90)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 80%.png").scaled(500,20));
        else if(player_2->getVida()>=70 && player_2->getVida()<80)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 70%.png").scaled(500,20));
        else if(player_2->getVida()>=60 && player_2->getVida()<70)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 60%.png").scaled(500,20));
        else if(player_2->getVida()>=50 && player_2->getVida()<60)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 50%.png").scaled(500,20));
        else if(player_2->getVida()>=40 && player_2->getVida()<50)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 40%.png").scaled(500,20));
        else if(player_2->getVida()>=30 && player_2->getVida()<40)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 30%.png").scaled(500,20));
        else if(player_2->getVida()>=20 && player_2->getVida()<30)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 20%.png").scaled(500,20));
        else if(player_2->getVida()>=10 && player_2->getVida()<20)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 10%.png").scaled(500,20));
        else if(player_2->getVida()>=0 && player_2->getVida()<10)
            barra_p2->setPixmap(QPixmap(":/Imagenes/barra 0%.png").scaled(500,20));
}
}

QString Nivel_1::int2str(long a){
    int c=0,i=1;
    char e;
    QString b;
    for(;(a/i);i=i*10)
        c++;
    for(int j=0;j<c;j++){
        i/=10;
        e=(a/i)+48;
        b.push_back(e);
        a-=(a/i)*i;
    }
    return b;
}

