#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPixmap>

#include "nivel_1.h"
#include "nivel_2.h"
#include "nivel_3.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_bot_nil_1_clicked();

    void on_bot_nil_2_clicked();

    void on_pushButton_clicked();

    void on_but_ski_1_clicked();

    void on_but_ski_2_clicked();

    void on_bot_nil_3_clicked();

private:
    Ui::Menu *ui;
    Nivel_1 *level1;
    Nivel_2 *level2;
    Nivel_3 *level3;
    int skin=0;
};
#endif // MENU_H
