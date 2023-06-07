#include "enemigos.h"

Enemigos::Enemigos()
{
    enemigos = new QPixmap;
    derecha = new QPixmap;
    izquierda = new QPixmap;
    enemigos->load(":/Sprites/Enemigos.png");
    derecha->load(":/Sprites/Enemigo Derecha.png");
    izquierda->load(":/Sprites/Enemigo Izquierda.png");
    scale = 2.2;
    vida = 50;
    direccion = 6;
    shoot = new Disparo;
    Movimiento=false;
    timerCambioDireccion = new QTimer(this);
    connect(timerCambioDireccion, &QTimer::timeout, this, &Enemigos::cambiarDireccion);
    timerCambioDireccion->start(5000);  // Cambiar dirección cada 5 segundos

    timerDisparo = new QTimer(this);
    connect(timerDisparo, &QTimer::timeout, this, &Enemigos::disparar);
    timerDisparo->start(5000);  // Disparar cada 3 segundos
}


Enemigos::~Enemigos()
{
    delete enemigos;
    delete derecha;
    delete izquierda;
    delete timerCambioDireccion;
    delete timerDisparo;
}

int Enemigos::getvida()
{
    return vida;
}

void Enemigos::setvida(int life)
{
    this->vida=life;
}

void Enemigos::Puede_moverse(bool Movimiento)
{
    this->Movimiento=Movimiento;
}

void Enemigos::cambiarDireccion()
{
    if (Movimiento){
        if (direccion == 6) {
            direccion = 12;
            setImage(derecha);
        } else {
            direccion = 6;
            setImage(izquierda);
        }
    }
}

void Enemigos::Elegirsprite(int x)
{
    *enemigos = enemigos->copy(x * Ancho_enemigo, 20, Ancho_enemigo, Alto_enemigo);
    setImage(enemigos);
}


void Enemigos::setImage(QPixmap *sprite)
{
    QPixmap pixmapScaled = sprite->scaled(sprite->width() * scale, sprite->height() * scale);
    setPixmap(pixmapScaled);
}


bool Enemigos::Rango_vision(Jugador* player)
{
    QPointF enemyPos = pos();
    QPointF playerPos = player->pos();
    qreal distancia = qSqrt(qPow(enemyPos.x() - playerPos.x(), 2) + qPow(enemyPos.y() - playerPos.y(), 2));

    if (distancia <= distancia_ver) {
        return true;
    } else {
        return false;
    }
}

int Enemigos::getdireccion()
{
    return direccion;
}

bool Enemigos::getmovimiento()
{
    return Movimiento;
}

void Enemigos::disparar()
{
    Disparo* disparo = new Disparo();
    disparo->posicionar(x(), y());
    emit disparoGenerado(this,disparo);
}

