#include "mapas.h"

Mapa::Mapa()
{
    Muro_prision = new QPixmap;
    Fondo1 = new QPixmap;
    is_a_wall = -1;
    scale = 2;
}

Mapa::~Mapa()
{
    delete Muro_prision;
    delete Fondo1;
}

void Mapa::is_wall(int x)
{
    is_a_wall = x;
    setImagen();
}

bool Mapa::is_muro()
{
    return is_a_wall != -1;
}

void Mapa::setImagen()
{
    if(is_a_wall==1){
        Muro_prision->load(":/Sprites/Muro_nivel_1.png");
    }

    setPixmap(Muro_prision->scaled(Muro_prision->width() * scale,
                                   Muro_prision->height() * scale));
}
