#include "disparo.h"

Disparo::Disparo()
{
    bala_der = new QPixmap;
    bala_der->load(":/Sprites/Disparo Derecha.png");
    bala_izq = new QPixmap;
    bala_izq->load(":/Sprites/Disparo Izquierda.png");
    velocityY = 0;
    velocityX = 0;
    aceleracionx = 0;
    aceleraciony = 9.8 ;
    player = new Jugador;
    scale=0.3;
    T=0.2;
    delta=0.4;
    shot = new QTimer(this);
    connect(shot, &QTimer::timeout, this, &Disparo::applyGravity);
    shot->start(100);
}

Disparo::~Disparo()
{
    delete bala_der;
    delete player;
    delete bala_izq;
    delete shot;
}

void Disparo::dir_disparo(int dir, bool permitir)
{
    if (dir==6 && permitir){
        aceleracionx = 200;
        aceleraciony = 50;
        velocityY -=50;
        velocityX += 80;
    }
    else if(dir==12 && permitir){
        aceleracionx = -200;
        aceleraciony = -50;
        velocityY +=50;
        velocityX -= 80;
    }
}

void Disparo::posicionar(int x, int y)
{
    if (x>900){
        setImage(bala_izq);
    }
    else
        setImage(bala_der);
    setPos(x,y);
    posx=x;
    posy=y;
}

void Disparo::cinematica()
{
    velocityX += aceleracionx*T*delta;
    velocityY += aceleraciony*T*delta;
    posx += velocityX*T*delta;
    posy += velocityY*T*delta;
    setPos(posx,posy);
    if (collidesWithItem(player))
        emit MatarJugador();
}

void Disparo::applyGravity()
{
    cinematica();
    double dt = 0.01; // Paso de tiempo
    velocityX += aceleracionx * dt;
    velocityY += aceleraciony * dt;

    posx += velocityX * dt;
    posy += velocityY * dt;

    setPos(posx, posy);
    if (collidesWithItem(player))
        emit MatarJugador();
}

void Disparo::setImage(QPixmap *sprite)
{
    setPixmap(sprite->scaled(sprite->width()*scale,
                                    sprite->height()*scale));
}
