#ifndef AVISO_H
#define AVISO_H

#include <QMainWindow>

namespace Ui {
class aviso;
}

class aviso : public QMainWindow
{
    Q_OBJECT

public:
    explicit aviso(QWidget *parent = nullptr);
    ~aviso();
    void mostrar();
    void ganar();
    void perder();

private:
    Ui::aviso *ui;
};

#endif // AVISO_H
