#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent): QMainWindow(parent), ui(new Ui::Menu){
    ui->setupUi(this);

    level1= new Nivel_1;
    level2= new Nivel_2;
    level3= new Nivel_3;

    ui->bot_nil_1->setEnabled(false);
    ui->bot_nil_2->setEnabled(false);
    ui->bot_nil_3->setEnabled(false);
}

Menu::~Menu(){
    delete ui;
    delete level1;
    delete level2;
    delete level3;
}


void Menu::on_bot_nil_1_clicked(){
    this->close();
    level1->show();
}

void Menu::on_bot_nil_2_clicked(){
    this->close();
    level2->show();
}

void Menu::on_pushButton_clicked(){
    this->close();
    level3->show();
}

void Menu::on_but_ski_1_clicked(){
    skin=1;
    QString ban="activado ";
    ban.push_back(char(skin+48));
    ui->label_8->setText(ban);
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}

void Menu::on_but_ski_2_clicked(){
    skin=2;
    QString ban="activado ";
    ban.push_back(char(skin+48));
    ui->label_8->setText(ban);
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}

void Menu::on_bot_nil_3_clicked(){
    skin=3;
    QString ban="activado ";
    ban.push_back(char(skin+48));
    ui->label_8->setText(ban);
    ui->bot_nil_1->setEnabled(true);
    ui->bot_nil_2->setEnabled(true);
    ui->bot_nil_3->setEnabled(true);
}
