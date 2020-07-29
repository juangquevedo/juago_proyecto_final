//Librerías
#include "a_jugar.h"
#include "ui_a_jugar.h"

a_jugar::a_jugar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::a_jugar)
{
    ui->setupUi(this);
    menu1 = new Menu() ;
    menu2 = new menu_2_jugadores();

}

a_jugar::~a_jugar()
{
    delete ui;
    delete menu1;
    delete menu2;
}

//Botón un jugador
void a_jugar::on_un_jugador_clicked()
{
    name = ui->inputname->text();
    if (name!=""){
    menu1->show();
    this->close();
    }
}


void a_jugar::on_dos_jugadores_clicked()
{
   name = ui->inputname->text();
   if(name!=""){
        menu2->show();
        this->close();
   }

}


//void menu::on_Cargar_clicked()
//{
//        QString info;

//        QFile file("Guardar.txt");
//        file.open(QIODevice::ReadOnly);
//        info=file.readLine();

//        QList <QString> cargar;
//        int n=0;
//        while(n>=0){
//            n = info.indexOf("\t");
//            if(n!=0){
//                cargar.append(info.left(n));
//            }
//            info=info.remove(0,n+1);
//        }

//        juego1->personx= cargar.at(0).toFloat();
//        juego1->persony= cargar.at(1).toFloat();
//        juego1->personvx= cargar.at(2).toFloat();
//        juego1->personvy=cargar.at(3).toFloat();
//        juego1->puntaje=cargar.at(4).toInt();
//        juego1->min=cargar.at(5).toInt();
//        juego1->seg=cargar.at(6).toInt();

//        juego1->show();
//        juego1->setDosjugadores(false);
//        this->close();

//}






