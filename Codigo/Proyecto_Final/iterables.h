#ifndef ITERABLES_H
#define ITERABLES_H

#define Ancho_objeto 64
#define Alto_Objeto 60

#include <QObject>
#include <QGraphicsPixmapItem>

class iterables : public QGraphicsPixmapItem, public QObject
{
public:
    iterables();
    ~iterables();
    void ElegirSprite(int x, int tipo);
    void type_object();
private:
    QPixmap *Puerta, *Objeto, *rendija;
    void setImage();
    int object, scale_p;
    qreal scale_o;
};

#endif // ITERABLES_H
