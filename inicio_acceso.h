#ifndef INICIO_ACCESO_H
#define INICIO_ACCESO_H
//Librerías
#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QTimer>
#include <iostream>

#include "a_jugar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class inicio_acceso; }
QT_END_NAMESPACE

class inicio_acceso : public QMainWindow
{
    Q_OBJECT

public:
    inicio_acceso(QWidget *parent = nullptr);
    ~inicio_acceso();
    int ok = 0;
    int ques = 1;
    int res= 0;
    int good = 0;

    QPixmap imag_access;
    QTimer *fin;

void control();
void ocultar();
void organizar(int preg1_y, int preg2_y, int preg3_y, int preg4_y);

private slots:
void final();
void on_inicio_clicked();

private:
    Ui::inicio_acceso *ui;
    a_jugar *a_jugar1;

};
#endif // INICIO_ACCESO_H
