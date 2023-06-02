#ifndef JUGADOR_H
#define JUGADOR_H

#define Velocidad_Jugador 8

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QTimer>

class Jugador : public QGraphicsRectItem, public QObject
{
public:
    Jugador();
    ~Jugador();
    void move_jugador(int type);

private:
    void applyGravity();
    void jump();
    qreal velocityY;
    bool isJumping;
    QTimer *timer;
};

#endif // JUGADOR_H
