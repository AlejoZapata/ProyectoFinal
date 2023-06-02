#include "juego.h"

Juego::Juego()
{
    Agregar_Jugador();
}

Juego::~Juego()
{
    delete p_pal;
}

void Juego::Agregar_Jugador()
{
    p_pal=new Jugador();
    addItem(p_pal);
    p_pal->setZValue(1);
    p_pal->setPos(10,500);
}

void Juego::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_W:
            p_pal->move_jugador(3);
            break;
        case Qt::Key_S:
            p_pal->move_jugador(1);
            break;
        case Qt::Key_A:
            p_pal->move_jugador(0);
            break;
        case Qt::Key_D:
            p_pal->move_jugador(2);
            break;
        default:
            break;
    }
}
