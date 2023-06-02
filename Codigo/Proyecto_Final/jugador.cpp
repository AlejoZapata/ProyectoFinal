#include "jugador.h"
#include <QBrush>
#include <QKeyEvent>
#include <QTimer>

Jugador::Jugador()
{
    setRect(0, 0, 50, 50);
    setBrush(QBrush(Qt::red));

    velocityY = 0;
    isJumping = false;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Jugador::applyGravity);
    timer->start(16); // 60 FPS (aproximadamente)
}

Jugador::~Jugador()
{
    delete timer;
}

void Jugador::move_jugador(int type)
{
    switch (type) {
    case 0:
        setX(x() - Velocidad_Jugador);
        break;
    case 1:
        setY(y() + Velocidad_Jugador);
        break;
    case 2:
        setX(x() + Velocidad_Jugador);
        break;
    case 3:
        if (!isJumping)
            jump();
        break;
    default:
        break;
    }
}

void Jugador::applyGravity()
{
    const qreal gravity = 9.8;
    const qreal maxVelocityY = 10;

    // Aplicar gravedad
    velocityY += gravity;
    velocityY = qMin(velocityY, maxVelocityY);

    // Actualizar posición vertical
    setY(y() + velocityY);

    const qreal groundLevel = 500;
    if (y() >= groundLevel) {
        setY(groundLevel);
        velocityY = 0;
        isJumping = false;
    }
}

void Jugador::jump()
{
    const qreal jumpVelocity = -50;
    velocityY = jumpVelocity;
    isJumping = true;
}
