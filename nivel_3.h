#ifndef NIVEL_3_H
#define NIVEL_3_H

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
class Nivel_3;
}

class Nivel_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_3(QWidget *parent = nullptr);
    ~Nivel_3();
    void keyPressEvent(QKeyEvent * event);
    void setskin(int skin);

private slots:


private:
    Ui::Nivel_3 *ui;
    QGraphicsScene *scene;
    QGraphicsView * view;
    personaje *player;
    QList <enemigos *> enemys;
};

#endif // NIVEL_3_H
