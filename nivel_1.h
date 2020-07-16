#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QMainWindow>
#include <QGraphicsScene>
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
class Nivel_1;
}

class Nivel_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();

private slots:


private:
    Ui::Nivel_1 *ui;
    int skin;
    QGraphicsScene *scene;
};

#endif // NIVEL_1_H
