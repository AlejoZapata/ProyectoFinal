#include "jugador.h"
#include <QTimer>

Jugador::Jugador()
{
    Personaje=new QPixmap;
    Movimiento=new QPixmap;
    Personaje->load(":/Sprites/Sprites.png");
    modoSigilo=false;
    *Personaje=Personaje->copy(Pos_sprite_Jugador_x,Pos_sprite_Jugador_y,
                     Ancho_jugador_up*col_sprite,
                     Alto_jugador_up*filas_sprite);
    cant_sprites=12;
    scale=3;
    velocityY = 0;
    velocityX = 0;
    groundLevels = {170, 425, 370};
    T=0.2;
    currentFloor = 0;
    isJumping = false;
    aceleracionx = 0;
    aceleraciony = 0 ;
    delta = 0.4;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Jugador::applyGravity);
    timer->start(T*500);
}

Jugador::~Jugador()
{
    delete Personaje;
    delete Movimiento;
    delete timer;
}

void Jugador::move_jugador(int type)
{
    switch (type) {
    case 0:
            aceleracionx = 190;
            velocityX -= impx;
        break;
    case 1:
        break;
    case 2:
        aceleracionx = -190;
        velocityX += impx;
        //setX(x() + Velocidad_Jugador); // Mover hacia la derecha
        break;
    case 3:
        if (!isJumping){
            aceleraciony = 190;
            velocityY -= impy;
            isJumping=true;
        }
        break;
    default:
        break;
    }
}

void Jugador::ElegirSprite(int x, int y)
{
    if(x < col_sprite && y<filas_sprite && !isModoSigilo()){
        *Movimiento=Personaje->copy(x*Ancho_jugador_up,y*Alto_jugador_up,
                                  Ancho_jugador_up,Alto_jugador_up);
    setImage();
    }
    else{
        *Movimiento=Personaje->copy(x*Ancho_jugador_down,y*Alto_jugador_down,
                                  Ancho_jugador_down,Alto_jugador_down);
    setImage();
    }
}

void Jugador::setImage()
{
    setPixmap(Movimiento->scaled(Movimiento->width()*scale,
                                    Movimiento->height()*scale));
}

void Jugador::posicionar(int x, int y)
{
    setPos(x,y);
    posx=x;
    posy=y;
}

void Jugador::ActualizarMovimiento(int type)
{
    if(!isModoSigilo()){
        if (type==0){
            if(cant_sprites>=12) cant_sprites=12;
            ElegirSprite(cant_sprites,0);
            cant_sprites--;
            if(cant_sprites==9) cant_sprites = 12;
        }
        else if(type==2){
            if(cant_sprites<=13) cant_sprites=13;
            ElegirSprite(cant_sprites,0);
            cant_sprites++;
            if(cant_sprites==16) cant_sprites = 13;
        }
        else
            ElegirSprite(8,0);
        }
    else{
        if (type==0){
            if(cant_sprites>=3) cant_sprites=3;
            ElegirSprite(cant_sprites,2);
            cant_sprites--;
            if(cant_sprites==0) cant_sprites = 3;
        }
        else if (type==2){
            if(cant_sprites<=4) cant_sprites=4;
            ElegirSprite(cant_sprites,2);
            cant_sprites++;
            if(cant_sprites==7) cant_sprites = 4;
        }
    }
}

void Jugador::setAceleracionx(int aceleracionX)
{
    this->aceleracionx=aceleracionX;
}

void Jugador::setAceleraciony(int aceleracionY)
{
    this->aceleraciony=aceleracionY;
}

void Jugador::setvelocityx(int velocityx)
{
    this->velocityX=velocityx;
}

void Jugador::setvelocityy(int velocityy)
{
    this->velocityY=velocityy;
}


void Jugador::setmodoSigilo()
{
    modoSigilo = !modoSigilo;
}

bool Jugador::isModoSigilo()
{
    if (modoSigilo) return true;
    else return false;
}

void Jugador::cinematica()
{
    velocityX += aceleracionx*T*delta;
    velocityY += aceleraciony*T*delta;
    posx += velocityX*T*delta;
    posy += velocityY*T*delta;
    setPos(posx,posy);
}

void Jugador::setfloor(int piso_act)
{
    this->currentFloor=piso_act;
}


void Jugador::applyGravity()
{
    cinematica();
    if((aceleracionx < 0 && velocityX <= 0) || (aceleracionx > 0 && velocityX >= 0)){
        velocityX = 0;
        aceleracionx = 0;
    }

    qreal groundLevel = groundLevels[currentFloor]; // Obtener el groundLevel del piso actual
    if (y() >= groundLevel) {
        setY(groundLevel);
        velocityY = 0;
        isJumping = false;
    }
}
