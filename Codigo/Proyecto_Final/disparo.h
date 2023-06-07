#ifndef DISPARO_H
#define DISPARO_H

#include <QObject>
#include "jugador.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class Disparo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Disparo();
    ~Disparo();
    void dir_disparo(int dir, bool permitir);
    void posicionar(int x, int y);
signals:
    void MatarJugador();
public slots:
    void applyGravity();
private:
    QPixmap* bala_der;
    QPixmap* bala_izq;
    QTimer* shot;
    qreal velocityX;
    qreal velocityY;
    qreal aceleracionx;
    qreal aceleraciony;
    qreal scale;
    qreal T;
    qreal delta;
    qreal posx;
    qreal posy;
    Jugador *player;
    void cinematica();
    void setImage(QPixmap* sprite);
};

#endif // DISPARO_H
