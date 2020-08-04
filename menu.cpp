#include "menu.h"
#include "ui_menu.h"
#include "aviso.h"

Menu::Menu(QWidget *parent): QMainWindow(parent), ui(new Ui::Menu){
    ui->setupUi(this);

    level1= new Nivel_1;

    //se desabilita los botones para no causar errores
    ui->bot_nil_1->setEnabled(false);
    ui->bot_nil_2->setEnabled(false);
    ui->bot_nil_3->setEnabled(false);
}

Menu::~Menu(){
    delete ui;
    delete level1;
}


void Menu::on_bot_nil_1_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel
    //level1->guardar(skin,0,0);
    level1->setskin(skin);
    level1->cargar_nivel();
    level1->show();
    this->close();
}

void Menu::on_bot_nil_2_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel

    level1->nivel_2();
    level1->setskin(skin);
    level1->cargar_nivel();
    level1->show();
    this->close();
}

void Menu::on_bot_nil_3_clicked(){
    //llama la funcion de escoger la apariencia del personaje y luego cargar el nivel
    level1->nivel_3();
    level1->setskin(skin);
    level1->cargar_nivel();
    level1->show();
    this->close();
}

void Menu::on_but_ski_1_clicked(){
    //cambia la variable de la apariencia
    skin=1;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}

void Menu::on_but_ski_2_clicked(){
    //cambia la variable de la apariencia
    skin=2;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}



void Menu::on_but_ski_3_clicked(){
    //cambia la variable de la apariencia
    skin=3;
    //se habilitan los botones para cargar el nivel
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}


void Menu::on_pushButton_clicked()
{
    //boton de ayuda
    aviso *b= new aviso;
    (*b).show();

}
