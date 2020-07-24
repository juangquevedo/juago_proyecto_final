#include "menu.h"
#include "nivel_1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Menu w;
    Nivel_1 w;
    w.show();
    return a.exec();
}
