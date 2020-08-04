#include "menu.h"

#include "nivel_1.h"
#include "inicio_acceso.h"
#include "menu_2_jugadores.h"
#include "a_jugar.h"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    inicio_acceso w;
    w.show();
    return a.exec();
}
