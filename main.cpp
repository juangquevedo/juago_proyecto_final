#include "menu.h"
#include "menu_2_jugadores.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_2_jugadores w;
    w.show();
    return a.exec();
}
