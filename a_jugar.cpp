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
        ifstream f(jugador1.str().c_str());

        bool exist = f.good();
        if (exist){
            {ifstream (jugador1.str().c_str(), ios::out | ios::in);}


        }
        else{
                QMessageBox mensaje;
                mensaje.setText("¡No tienes una partida guardada!");
                mensaje.exec();

        }
    }


//    if (read.is_open())
//       {
//           while (!read.eof())
//           {
//               // Obtiene linea del archivo
//               read.getline(ln, 500);

//               // Itemize la cadena para obtener cada uno de los elementos necesarios
//               pch = strtok (ln," ");
//               pt = 0;
//               while (pch != NULL)
//               {
//                   // Muestro el contenido de info para ver que los campos se obtiene de modo adecuado
//
//                   cout<< info[pt] << pch << endl;
//                   pch = strtok (NULL, " ");

//                   pt ++;
//                   if(pt > 2)
//                   {
//                       // En caso de que la cadena contengas mas campos de los que puedo procesar
//                       break;
//                   }
//               }

//               cont ++;
//           }
//       }
//       else
//       {
//           cout << "¡Error! El archivo no pudo ser abierto." << endl;
//       }

//       read.close();
//   }
//    QString info;

//       QFile file("Guardar.txt");
//       file.open(QIODevice::ReadOnly);
//        info=file.readLine();
//        QList <QString> cargar;
//        int n=0;
//         while(n>=0){

//             n = info.indexOf("\t");
//            if(n!=0){
//                   cargar.append(info.left(n));
//               }
//               info=info.remove(0,n+1);
//           }

//            Nivel_1->player= cargar.at(0).toFloat();
//             Nivel_1->persony= cargar.at(1).toFloat();
//              Nivel_1->personvx= cargar.at(2).toFloat();
//                 juego1->personvy=cargar.at(3).toFloat();
//                 juego1->puntaje=cargar.at(4).toInt();
//                 juego1->min=cargar.at(5).toInt();
//                 juego1->seg=cargar.at(6).toInt();

//                 juego1->show();
//                 juego1->setDosjugadores(false);
//                 this->close();

}


//void a_jugar::on_Cargar_clicked()
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

