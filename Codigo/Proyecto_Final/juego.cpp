#include "juego.h"

Juego::Juego()
{
    Agregar_Jugador();
    scale=2;
    crear_Mapa();
    set_background(":/Sprites/Fondo prision.jpeg",scale);
}

Juego::~Juego()
{
    delete p_pal;
}

void Juego::Agregar_Jugador()
{
    p_pal=new Jugador();
    p_pal->ElegirSprite(8,0);
    addItem(p_pal);
    p_pal->setZValue(1);
    p_pal->posicionar(40,170);
    setFocusItem(p_pal);
}

void Juego::crear_Mapa()
{
    for(int y=0;y<total_y_bloques;y++){
        for(int x=0;x<total_x_bloques;x++){
            bl_mapa[x][y] = new Mapa;
            if(x==0 || y==0 || x == total_x_bloques-1 || y==total_y_bloques-1 || y%4==0 || x==total_x_bloques/2)  {
                bl_mapa[x][y]->is_wall(1);
            }
            bl_mapa[x][y]->setPos(Ancho_bloque_1*scale*x,Alto_bloque_1*scale*y);
            addItem(bl_mapa[x][y]);
            bl_mapa[x][y]->setZValue(1);
        }
    }
}

bool Juego::ComprobarColision(QGraphicsItem *item, short dir, int Ancho, int Alto)
{
    unsigned short x = item->x(), y = item->y(),
            x1, y1;
    bool move = true;

    switch (dir) {
        case 0: // Izquierda
            x -= impx;
            x1 = x;
            y1 = y + Alto * scale - 1;
            break;
        case 1: // Abajo
            y += Alto * scale - 1 + impy;
            x1 = x + Ancho * scale - 1;
            y1 = y;
            break;
        case 2: // Derecha
            x += Ancho * scale - 1 + impx;
            x1 = x;
            y1 = y + Alto * scale - 1;
            break;
        case 3: // Arriba
            y -= impy;
            x1 = x + Ancho * scale - 1;
            y1 = y;
            break;
        default:
            break;
    }
    // Comprobar colisión con los bloques
    if (bl_mapa[(x / (Ancho*scale))][(y / (Alto*scale))]->is_muro() ||
        bl_mapa[(x1 / (Ancho*scale))][(y1 / (Alto*scale))]->is_muro()) {
        p_pal->setAceleracionx(0);
        p_pal->setAceleraciony(0);
        p_pal->setvelocityx(0);
        p_pal->setvelocityy(0);
        move = false;
    }
    return move;
}

void Juego::set_background(QString name, int scale)
{
    QImage k;
    QBrush n;

    k.load(name);
    k = k.scaled(k.width()*scale,k.height()*scale);
    n.setTextureImage(k);
    setBackgroundBrush(n);
}

void Juego::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_W:
            p_pal->ActualizarMovimiento(3);
            p_pal->move_jugador(3);
            break;
        case Qt::Key_A:
            p_pal->ActualizarMovimiento(0);
            if (ComprobarColision(p_pal, 0, Ancho_bloque_1, Alto_bloque_1)) {
                p_pal->move_jugador(0);
            }
            break;
        case Qt::Key_D:
            p_pal->ActualizarMovimiento(2);
            if (ComprobarColision(p_pal, 2, Ancho_bloque_1, Alto_bloque_1)) {
                p_pal->move_jugador(2);
            }
            break;
        case Qt::Key_C:
            if (!p_pal->isModoSigilo()) {
                p_pal->ElegirSprite(1, 0);
            }
            p_pal->setmodoSigilo();

            if (p_pal->isModoSigilo()) {
                p_pal->cant_sprites = 2;
            } else {
                p_pal->cant_sprites = 12;
                p_pal->ElegirSprite(1, 0);
            }
            break;

        default:
            break;
    }
}



