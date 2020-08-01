#include "inicio_acceso.h"
#include "ui_inicio_acceso.h"
#include <QMediaPlayer>

a_jugar *a_jugar1;
inicio_acceso::inicio_acceso(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inicio_acceso)
{
    ui->setupUi(this);
    a_jugar1 = new a_jugar();
    ui->preg1->hide();
    ui->preg2->hide();
    ui->preg3->hide();
    ui->preg4->hide();
    soundrack = new QMediaPlayer;
    soundrack-> setMedia(QUrl("qrc:/Audios/background-suspense-music-suspenseful-dramatic-film-soundtracks-anticipation.mp3"));
    soundrack->setVolume(0);
    soundrack->play();
    fin = new QTimer(this);
    fin-> stop();
    connect(fin,SIGNAL(timeout()),this,SLOT(final()));

}

inicio_acceso::~inicio_acceso()
{
    delete ui;
    delete a_jugar1;
    delete fin;
}

void inicio_acceso::on_inicio_clicked()
{
    ui->inicio->setText("Siguiente");
    control();
}
void inicio_acceso::organizar(int preg1_y, int preg2_y, int preg3_y, int preg4_y)

{
    ui->preg1->move(200,preg1_y);
    ui->preg2->move(200,preg2_y);
    ui->preg3->move(200,preg3_y);
    ui->preg4->move(200,preg4_y);
}

void inicio_acceso::control()
{
    ui->preg1->show();
    ui->preg2->show();
    ui->preg3->show();
    ui->preg4->show();

    if (ui->preg1->isChecked()){res=1;}
    if (ui->preg2->isChecked()){res=2;}
    if (ui->preg3->isChecked()){res=3;}
    if (ui->preg4->isChecked()){res=4;}

    if(ques==1){
        imag_access.load(":/Imagenes/inicio/punto2.PNG");
        ui->label->setPixmap(imag_access);

    }
    if(ques==2){
        imag_access.load(":/Imagenes/inicio/punto1.PNG");
        ui->label->setPixmap(imag_access);

        if(res==2){good++;}
    }

    if(ques==3){
        imag_access.load(":/Imagenes/inicio/punto3.PNG");
        ui->label->setPixmap(imag_access);

        if(res==1){good++;}

    }

    if(ques==4){
        imag_access.load(":/Imagenes/inicio/punto4.PNG");
        ui->label->setPixmap(imag_access);

        if(res==3){good++;}
    }

    if(ques==5){
        QString total;
        ocultar();
        if(res==4){good++;}
        if(good>2){
            total = QString::number(good);
            ui->good->setText(total);
            ok=1;
            imag_access.load(":/Imagenes/inicio/bien_hecho.PNG");
            ui->label->setPixmap(imag_access);
        }
        else{
            total = QString::number(4-good);
            ui->good->setText(total);
            ok=0;
            imag_access.load(":/Imagenes/inicio/mal_hecho.PNG");
            ui->label->setPixmap(imag_access);}

        ques++;
    }

    if (ques==6){fin->start(6000);}

    ques++;
}

void inicio_acceso::ocultar()
{
    ui->preg1->hide();
    ui->preg2->hide();
    ui->preg3->hide();
    ui->preg4->hide();
    ui->inicio->hide();
}

void inicio_acceso::final()
{
    if(ok==1){
        this->close();
        a_jugar1->show();
        fin->stop();
    }
    if(ok==0){
        this->close();
        fin->stop();
    }
}




