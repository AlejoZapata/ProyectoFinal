#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#define Ancho_enemigo 30
#define Alto_enemigo 50
#define distancia_ver 50
#define cant_mov 9

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPainter>
#include "jugador.h"
#include "disparo.h"

class Enemigos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemigos();
    ~Enemigos();
    void Elegirsprite(int x);
    int getvida();
    void setvida(int life);
    void Puede_moverse(bool Movimiento);
    bool Rango_vision(Jugador* player);
    int getdireccion();
    void setdireccion(int dir);
    bool getmovimiento();
signals:
    void disparoGenerado(Enemigos* enemy, Disparo* disparo);
public slots:
    void cambiarDireccion();
    void disparar();
private:
    QPixmap *enemigos, *derecha, *izquierda;
    QTimer *timerCambioDireccion;
    QTimer *timerDisparo;
    void Act_mov(int dir);
    int vida, cant_sprites;
    Disparo *shoot;
    bool Movimiento;
    void setImage(QPixmap *sprite);
    qreal scale;
    int direccion, velocidad;
};

#endif // ENEMIGOS_H
