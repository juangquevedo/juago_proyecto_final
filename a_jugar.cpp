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
        ostringstream jugador1;
        jugador1<<name.toStdString() << ".txt";
        ifstream f(jugador1.str().c_str());

        bool exist = f.good();
        if (exist){
            QMessageBox mensaje;
            mensaje.setText("¡La partida ya existe!");
            mensaje.exec();
        }
        else{
            {
                ofstream new_game(jugador1.str().c_str(), ios::out | ios::trunc);}
            menu1->show();
            this->close();}
    }
}


void a_jugar::on_dos_jugadores_clicked()
{

    name = ui->inputname->text();
    if(name!=""){
        ostringstream jugador1;
        jugador1<<name.toStdString() << ".txt";
        ifstream f(jugador1.str().c_str());

        bool exist = f.good();
        if (exist){
            QMessageBox mensaje;
            mensaje.setText("¡La partida ya existe!");
            mensaje.exec();
        }
        else{
            {
                ofstream new_game(jugador1.str().c_str(), ios::out | ios::trunc);}
            menu2->show();
            this->close();}
    }

}


void a_jugar::on_cargar_clicked()
{
    name = ui->inputname->text();
    if(name!=""){
        ostringstream jugador1;
        jugador1<<name.toStdString() << ".txt";
        ifstream file(jugador1.str().c_str());

        bool exist = file.good();
        if (exist){
            string element;
            int nivel;
            int jugadores;
            vector<int> skins={};
            vector<float> posxs={};
            vector<float> posys={};
            vector<int> vidas={};
            vector<float> enemys;

            while (file>>element){
                if (element=="Nivel"){
                    file>>nivel;
                }
                else if (element=="Jugadores") {
                    file>>jugadores;
                    for (int i=0; i<jugadores; i++ ) {
                        while (file>>element){
                            if (element=="Skin") {
                                int skin=0;
                                file>>skin;
                                skins.push_back(skin);
                            }
                            else if (element=="PosX") {
                                float posx=0.0;
                                file>>posx;
                                posxs.push_back(posx);
                            }
                            else if (element=="PosY") {
                                float posy=0.0;
                                file>>posy;
                                posys.push_back(posy);
                            }
                            else if (element=="Vida") {
                                int vida=0;
                                file>>vida;
                                vidas.push_back(vida);
                                break;
                            }
                        }

                    }

                }
                else if (element=="enemys") {
                   int cantenemys=0;
                   file>>cantenemys;
                   enemys= vector <float>(cantenemys*2,0);
                   for (int i=0; i<cantenemys*2; i++){
                       file>>enemys[i];
                   }


                }
                else if (element=="items") {


                }
            }

            level1= new Nivel_1(jugadores, nivel, vidas,posxs,posys,skins);
            level1->recarga_nivel(enemys);
            level1->show();
            this->close();
        }

        else{
            QMessageBox mensaje;
            mensaje.setText("¡No tienes una partida guardada!");
            mensaje.exec();

        }
    }
}


