#include "aviso.h"
#include "ui_aviso.h"

aviso::aviso(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aviso)
{
    ui->setupUi(this);
    ui->label->hide();
    ui->label_gan->hide();
    ui->label_per->hide();
}

aviso::~aviso()
{
    delete ui;
}

void aviso::mostrar()
{
ui->label->show();

}

void aviso::ganar(){
    ui->label_gan->show();
}

void aviso::perder(){
    ui->label_per->show();
}
