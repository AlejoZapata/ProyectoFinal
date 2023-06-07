#include "iterables.h"

iterables::iterables()
{
    Puerta = new QPixmap;
    Objeto = new QPixmap;
    scale_p=2;
    scale_o=1.8;
    Objeto->load(":/Sprites/Objetos.png");
    object=0;
}

iterables::~iterables()
{
    delete Puerta;
    delete Objeto;
}

void iterables::ElegirSprite(int x, int tipo)
{
    *Objeto=Objeto->copy(x*Ancho_objeto,0,Ancho_objeto,Alto_Objeto);
    object=tipo;
    setImage();
}

void iterables::setImage()
{
    if(object==0){
        Puerta->load(":/Sprites/Puerta.jpeg");
        setPixmap(Puerta->scaled(Puerta->width() * scale_p, Puerta->height() * scale_p));
    }
    else if(object==1){
        setPixmap(Objeto->scaled(Objeto->width() * scale_o, Objeto->height() * scale_o));
    }
}
