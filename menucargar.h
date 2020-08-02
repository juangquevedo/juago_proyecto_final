#ifndef MENUCARGAR_H
#define MENUCARGAR_H
#include <vector>
#include <QMainWindow>
#include "nivel_1.h"
using namespace std;
namespace Ui {
class menucargar;
}

class menucargar : public QMainWindow
{
    Q_OBJECT

public:
    explicit menucargar(int jugadores, int nivel, vector<int> &vidas,vector<float> &posxs,vector<float> &posys,vector<int> &skins,QWidget *parent = nullptr);
    ~menucargar();

private:
    Ui::menucargar *ui;
    Nivel_1 *level1;

};

#endif // MENUCARGAR_H
