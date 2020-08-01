#include "menucargar.h"
#include "ui_menucargar.h"

menucargar::menucargar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menucargar)
{
    ui->setupUi(this);
}

menucargar::~menucargar()
{
    delete ui;
}
