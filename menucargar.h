#ifndef MENUCARGAR_H
#define MENUCARGAR_H

#include <QMainWindow>

namespace Ui {
class menucargar;
}

class menucargar : public QMainWindow
{
    Q_OBJECT

public:
    explicit menucargar(QWidget *parent = nullptr);
    ~menucargar();

private:
    Ui::menucargar *ui;
};

#endif // MENUCARGAR_H
