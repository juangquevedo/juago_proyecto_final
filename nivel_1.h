#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include <QPixmap>
#include <QDebug>
#include <QApplication>

#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <personaje.h>
#include <enemigos.h>

namespace Ui {
class Nivel_1;
}

class Nivel_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();
    void keyPressEvent(QKeyEvent * event);
    void setskin(int skin);
    void crear_enemigos();

private slots:


private:
    Ui::Nivel_1 *ui;
    QGraphicsScene *scene;
    QGraphicsView * view;
    personaje *player;
    QList <enemigos *> enemys;

};

#endif // NIVEL_1_H
