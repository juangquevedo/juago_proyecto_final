#ifndef NIVEL_2_H
#define NIVEL_2_H

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

namespace Ui {
class Nivel_2;
}

class Nivel_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_2(QWidget *parent = nullptr);
    ~Nivel_2();

private slots:


private:
    Ui::Nivel_2 *ui;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView * view = new QGraphicsView(this);
};

#endif // NIVEL_2_H
