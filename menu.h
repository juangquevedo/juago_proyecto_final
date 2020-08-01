#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPixmap>
#include "personaje.h"
#include "nivel_1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    //variable para definir la apariencia del personaje
    int skin=0;

private slots:
    //funciones de los botones
    void on_bot_nil_1_clicked();

    void on_bot_nil_2_clicked();

    void on_but_ski_1_clicked();

    void on_but_ski_2_clicked();

    void on_bot_nil_3_clicked();

    void on_but_ski_3_clicked();

private:
    Ui::Menu *ui;
    //carga de los niveles
    Nivel_1 *level1;


};
#endif // MENU_H
