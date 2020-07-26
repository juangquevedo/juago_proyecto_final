#include "menu_2_jugadores.h"
#include "ui_menu_2_jugadores.h"

menu_2_jugadores::menu_2_jugadores(QWidget *parent) : QMainWindow(parent),ui(new Ui::menu_2_jugadores){
    ui->setupUi(this);

    level1= new Nivel_1;

    //se desabilita los botones para no causar errores
    ui->bot_nil_1->setEnabled(false);
    ui->bot_nil_2->setEnabled(false);
    ui->bot_nil_3->setEnabled(false);
}

menu_2_jugadores::~menu_2_jugadores(){
    delete ui;
    delete level1;
}

void menu_2_jugadores::on_but_ski_1_play_1_clicked(){
    //cambia la variable de la apariencia
    skin_1=1;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_2->setEnabled(false);
    ui->but_ski_2_play_2->setEnabled(true);
    ui->but_ski_3_play_2->setEnabled(true);
}

void menu_2_jugadores::on_but_ski_2_play_1_clicked(){
    //cambia la variable de la apariencia
    skin_1=2;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_2->setEnabled(true);
    ui->but_ski_2_play_2->setEnabled(false);
    ui->but_ski_3_play_2->setEnabled(true);
}

void menu_2_jugadores::on_but_ski_3_play_1_clicked(){
    //cambia la variable de la apariencia
    skin_1=3;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_2->setEnabled(true);
    ui->but_ski_2_play_2->setEnabled(true);
    ui->but_ski_3_play_2->setEnabled(false);
}

void menu_2_jugadores::on_but_ski_1_play_2_clicked(){
    //cambia la variable de la apariencia
    skin_2=1;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_1->setEnabled(false);
    ui->but_ski_2_play_1->setEnabled(true);
    ui->but_ski_3_play_1->setEnabled(true);
}

void menu_2_jugadores::on_but_ski_2_play_2_clicked(){
    //cambia la variable de la apariencia
    skin_2=2;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_1->setEnabled(true);
    ui->but_ski_2_play_1->setEnabled(false);
    ui->but_ski_3_play_1->setEnabled(true);
}

void menu_2_jugadores::on_but_ski_3_play_2_clicked(){
    //cambia la variable de la apariencia
    skin_2=3;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
    //se inhabilita la apariencia para el otro jugador
    ui->but_ski_1_play_1->setEnabled(true);
    ui->but_ski_2_play_1->setEnabled(true);
    ui->but_ski_3_play_1->setEnabled(false);
}

void menu_2_jugadores::on_bot_nil_1_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel
    level1->setskin(skin_1);
    level1->dos_jugadores(skin_2);
    level1->show();
    this->close();
}

void menu_2_jugadores::on_bot_nil_2_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel
    level1->setskin(skin_1);
    level1->dos_jugadores(skin_2);
    level1->show();
    this->close();
}

void menu_2_jugadores::on_bot_nil_3_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel
    level1->setskin(skin_1);
    level1->dos_jugadores(skin_2);
    level1->show();
    this->close();
}
