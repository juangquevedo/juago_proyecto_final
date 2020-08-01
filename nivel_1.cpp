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
    barra->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
    scene->addItem(barra);
    barra->setPos(player->x()-250,player->y()+150);

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
    fric=1.7;
    nive=2;
    view->resize(xvi,yvi+20);
    this->resize(xvi,yvi+20);
    scene->setSceneRect(0,0,xmap,ymap);
    scene->setBackgroundBrush(QBrush(QImage(":/new/prefix1/Imagenes/mapa edificio.png").scaled(xmap,ymap)));
    barra->setPos(100,yvi-30);
}

void Nivel_1::nivel_3(){
    //cambios para que el nivel concuerde con la ecena y suba la dificultad
    player->setPos(371,187);
    enemi+=15;
    nive=3;
}

void Nivel_1::keyPressEvent(QKeyEvent *event){
    //movimiento para cuando hay 1 jugador
    if(jugadores==1){
        if(event->key() == Qt::Key_W)
            player->mover_personaje(0,-1,fric);

        if(event->key() == Qt::Key_S)
            player->mover_personaje(0,1,fric);

        if(event->key() == Qt::Key_A)
            player->mover_personaje(-1,0,fric);

        if(event->key() == Qt::Key_D)
            player->mover_personaje(1,0,fric);
        //teclas para hallar ubicaciones
        if(event->key() == Qt::Key_I)
            player->setPos(player->x(),player->y()-1);
        if(event->key() == Qt::Key_K)
            player->setPos(player->x(),player->y()+1);
        if(event->key() == Qt::Key_J)
            player->setPos(player->x()-1,player->y());
        if(event->key() == Qt::Key_L)
            player->setPos(player->x()+1,player->y());
        if(event->key()==Qt::Key_Space)
            player->parar();
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
    //este es temporal para saber las ubicaciones de las paredes
    if(event->key() == Qt::Key_P){
        QMessageBox mensaje;
        QString b="X: "+int2str(player->x())+"Y: "+int2str(player->y());
        mensaje.setText(b);
        mensaje.exec();
    }
}

void Nivel_1::dos_jugadores(int skin_2){
    //essta funcion crea al jugador 2 y su barra de vida
    jugadores=2;
    player_2= new personaje;
    player_2->setSkin(skin_2);
    scene->addItem(player_2);
    if(nive==1)player_2->setPos(1990,1106);
    else if(nive==2) player_2->setPos(50,30);
    else player_2->setPos(371,227);

    barra_p2= new QGraphicsPixmapItem;
    barra_p2->setPixmap(QPixmap(":/new/prefix1/Imagenes/barra 100%.png").scaled(500,20));
    scene->addItem(barra_p2);
    barra_p2->setPos(player->x()-250,player->y()-270);
    if(nive==2) barra_p2->setPos(30,10);

    //aumenta los enemigos al doble
    enemi*=2;
}

void Nivel_1::setskin(int skin){
    //esta funcion la llama el menu para seleccionar la apariencia del personaje
    player->setSkin(skin);
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
    int x,y;
    bool ban;
    QList <paredes>::iterator it;
    srand(time(NULL));
    for(int i=0;i<enemi/2;){
        itemss.push_back(new items);
        x=10+rand()%((xmap-20)-9);
        y=10+rand()%((ymap-20)-9);
        ban=1;
        for(it=Lparedes.begin();it!=Lparedes.end();it++){
            if((*it).contacto(x,y,20,20)){
                ban=0;
                break;}
        }
        if(ban){
            itemss.back()->setPos(x,y);
            scene->addItem(itemss.back());
            i++;
        }
    }
}

void Nivel_1::act_per(){
    //esta funcion actualiza al personaje y a los enemigos
    int dx=player->x(),dy=player->y();
    QList <enemigos *>::iterator it=enemys.begin();
    player->actualizar(Lparedes,xmap,ymap);
    if(jugadores==2){
        player_2->actualizar(Lparedes,xmap,ymap);
        dx=(abs(player->x())+abs(player_2->x()))/2;
        dy=(abs(player->y())+abs(player_2->y()))/2;
    }
    //actualizo la vista y la barra de vida para que enfoquen al jugador o los jugadores
    view->centerOn(dx,dy);
    if((dx>(xvi/2) && dx<xmap-380)){
        barra->setPos(dx-250,barra->y());
        if(jugadores==2) barra_p2->setPos(dx-250,barra_p2->y());
    }
    if(dy>280 && dy<ymap-280){
        barra->setPos(barra->x(),dy+(yvi/2)-40);
        if(jugadores==2) barra_p2->setPos(barra_p2->x(),dy-(yvi/2)+40);
    }

    //en este ciclo se maneja el movimiento de los enemigos cuando son 2 jugadores
    if(jugadores==2){
        for(;it!=enemys.end();it++){
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
        mensaje.setText("Perdiste judor 1");
        mensaje.exec();
        scene->removeItem(player);
        time_items->stop();
        time_personje->stop();
    }
    if(jugadores==2 && !dead){
        if(player_2->getVida()<=0){
            QMessageBox mensaje;
            mensaje.setText("Perdiste jugador 2");
            mensaje.exec();
            scene->removeItem(player);
            time_items->stop();
            time_personje->stop();
        }
    }

    if(nive==1){
        if(player->x()>338 && player->x()<430 && player->y()>164 && player->y()<198){
            player->setPos(20000,20000);
            Nivel_1 *a= new Nivel_1;
            (*a).nivel_2();
            (*a).setskin(player->getSkin());
            (*a).player->setVida(player->getVida());
            if(jugadores==2){
                player_2->setPos(20000,20000);
                (*a).dos_jugadores(player_2->getSkin());
                (*a).player_2->setVida(player_2->getVida());}
            (*a).cargar_nivel();
            this->close();
            (*a).show();
        }
    }
    else if(nive==2){
        if(player->x()>1044 && player->x()<1098 && player->y()<28){
            player->setPos(20000,20000);
            Nivel_1 *a=new Nivel_1;
            (*a).nivel_3();
            (*a).setskin(player->getSkin());
            (*a).player->setVida(player->getVida());
            if(jugadores==2){
                player_2->setPos(20000,20000);
                (*a).dos_jugadores(player_2->getSkin());
                (*a).player_2->setVida(player_2->getVida());}
            (*a).cargar_nivel();
            this->close();
            (*a).show();
        }
    }
    else{
        if(player->x()>1934 && player->x()<1993 && player->y()>1079 && player->y()<1103){
            time_items->stop();
            time_personje->stop();
            QList <enemigos *>::iterator eli;
            for(eli=enemys.begin();eli!=enemys.end();eli++)
                scene->removeItem(*eli);
            enemys.clear();
            QMessageBox mensaje;
            mensaje.setText("Has sobrevivido al virus");
            mensaje.exec();
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

void Nivel_1::cargar_paredes(){
    string arch="paredes_n_1.txt",name,salida, s2;
    char s;
    int temp[4],pos=0;
    long long int tam;
    if(nive==2) arch="paredes_n_2.txt";
    fstream k_1(arch, ios::in | ios::ate);
    tam=k_1.tellg();
    k_1.close();
    fstream k(arch.c_str(), ios::in | ios::binary);
    for(long long int i=0;i<tam;i++){
        k.get(s);
        salida.push_back(s);
    }
    k.close();
    for(unsigned long int i=0;i<tam;i++){
        s=salida[i];
        if(salida[i]==',' || salida[i]=='\r'){
            temp[pos]=(str2int(name));
            name="";
            pos++;
        }
        else if(salida[i]=='\n'){
            Lparedes.push_back(paredes(temp[0],temp[1],temp[2],temp[3]));
            pos=0;
        }
        else
            name.push_back(salida[i]);
    }
}

void Nivel_1::cargar_nivel(){
    //inicio de enemigos e items
    cargar_paredes();
    crear_enemigos();
    crear_items();
    if(nive==3){
        QList <enemigos *>::iterator eli=enemys.begin();
        for(;eli!=enemys.end();eli++)
            (*eli)->setVel((*eli)->getVel()*2);
    }
    //inicio los timers ahora para que si se reflejen los cambios del nivel
    time_personje->start(10);
    time_items->start(10);
}

long Nivel_1::str2int(string a){
    int b,l,d=1,c=0;
    l=a.length();
    for(int i=l-1;i>=0;i--){
        b=a[i]-48;
        c+=b*d;
        d*=10;
    }
    return c;
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
