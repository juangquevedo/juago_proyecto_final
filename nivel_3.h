#ifndef NIVEL_3_H
#define NIVEL_3_H

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
class Nivel_3;
}

class Nivel_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Nivel_3(QWidget *parent = nullptr);
    ~Nivel_3();

private slots:


private:
    Ui::Nivel_3 *ui;
};

#endif // NIVEL_3_H
