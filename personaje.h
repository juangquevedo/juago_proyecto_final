#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    void setSkin(int skin);
};

#endif // PERSONAJE_H
