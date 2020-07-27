#ifndef ITEMS_H
#define ITEMS_H
#include <QGraphicsPixmapItem>

class items: public QGraphicsPixmapItem
{
public:
    items();
    void setcura(int c);
    int getcura();
    bool toque(int px, int py);
private:
    int cura=10;
};

#endif // ITEMS_H
