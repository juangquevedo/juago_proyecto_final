#include "menu.h"
#include "menu_2_jugadores.h"
#include "nivel_1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nivel_1 w;
    w.setskin(2);
    w.show();
    return a.exec();
}
