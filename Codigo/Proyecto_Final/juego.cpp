#include "juego.h"
#include "qapplication.h"

Juego::Juego()
{
    Agregar_Jugador();
    scale=2;
    crear_Mapa();
    Asignar_posicion_puerta();
    Asignar_objeto();
    Asignar_posicion_enemigos();
    timerEnemigos = new QTimer(this);
    connect(timerEnemigos, &QTimer::timeout, this, &Juego::actualizarEnemigos);
    int intervalo = 100;
    timerEnemigos->start(intervalo);
    set_background(":/Sprites/Fondo prision.jpeg",scale);
}

Juego::~Juego()
{
    delete p_pal;
    delete interactuar;
    delete enemy;
    delete timerEnemigos;
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

void Juego::Asignar_posicion_puerta()
{
    Agregar_Puertas(535, 90, 735, 90, 0);
    Agregar_Puertas(735, 90, 535, 90, 0);
    Agregar_Puertas(1145, 90, 1145, 345, 1);
    Agregar_Puertas(1145, 345, 1145, 90, 0);
    Agregar_Puertas(735, 345, 535, 345, 1);
    Agregar_Puertas(535, 345, 735, 345, 1);
}

void Juego::Agregar_Puertas(int origenX, int origenY, int destinoX, int destinoY, int piso)
{
    interactuar = new iterables;
    interactuar->setPos(origenX, origenY);
    interactuar->ElegirSprite(0, 0);
    addItem(interactuar);
    puertas.push_back(interactuar);
    destinos.push_back(QPointF(destinoX, destinoY));
    pisos.push_back(piso);
}

void Juego::Asignar_posicion_enemigos()
{
    Agregar_Enemigos(1115, 165, false);  // Primer enemigo, no se mueve
    Agregar_Enemigos(755, 415, true);   // Segundo enemigo, se mueve
    Agregar_Enemigos(60, 415, true);    // Tercer enemigo, se mueve
    Agregar_Enemigos(245, 425, false);
}

void Juego::agregarDisparo(Enemigos* enemy, Disparo* disparo)
{
    if (enemy->getmovimiento()) {
        addItem(disparo);
        disparo->dir_disparo(enemy->getdireccion(), enemy->getmovimiento());
    }
    if (p_pal->collidesWithItem(disparo))
        manejarJugadorAlcanzado();
    connect(disparo, &Disparo::MatarJugador, this, &Juego::manejarJugadorAlcanzado);

}

void Juego::manejarJugadorAlcanzado()
{
    QWidget* widget = QApplication::activeWindow();  // Obtener el puntero al widget principal
    if (widget) {
        QMessageBox::StandardButton respuesta = QMessageBox::question(widget, "¡Perdiste!", "Has perdido el juego. ¿Deseas reiniciar?",
                                                                      QMessageBox::Yes | QMessageBox::No);
        if (respuesta == QMessageBox::Yes) {
            QMessageBox::information(nullptr, "Eres una mierda, como pierdes xD", "Augustooo");;
        } else {
        }
    }
}


void Juego::Agregar_Enemigos(int x, int y, bool movimiento)
{
    Enemigos* enemy = new Enemigos();
    enemy->setPos(x, y);
    addItem(enemy);
    enemy->Elegirsprite(0);
    enemy->Puede_moverse(movimiento);
    cant_enemy.push_back(enemy);
    connect(enemy, &Enemigos::disparoGenerado, this, &Juego::agregarDisparo);
}


void Juego::actualizarEnemigos()
{
    for (auto it = cant_enemy.begin(); it != cant_enemy.end(); ) {
        Enemigos* enemigo = *it;
        if (enemigo->Rango_vision(p_pal)) {
            removeItem(enemigo);
            it = cant_enemy.erase(it);
            delete enemigo;
        } else {
            ++it;
        }
    }
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

void Juego::Asignar_objeto()
{
    Agregar_objeto(945, 165, 1);
    Agregar_objeto(945, 420, 1);
    Agregar_objeto(150, 420, 0);
    Agregar_objeto(325, 420, 0);
}


void Juego::Agregar_objeto(int x, int y, int tipo)
{
    interactuar = new iterables;
    interactuar->setPos(x, y);
    interactuar->ElegirSprite(tipo, 1);
    addItem(interactuar);
    objects.push_back(interactuar);
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
        case 6:
            x -= impx;
            x1 = x;
            y1 = y + Alto * scale - 1;
            break;
        case 12:
            x += Ancho * scale - 1 + impx;
            x1 = x;
            y1 = y + Alto * scale - 1;
            break;
        default:
            break;
    }

    // Comprobar colisión con los bloques y objetos
    if (bl_mapa[(x / (Ancho * scale))][(y / (Alto * scale))]->is_muro() ||
        bl_mapa[(x1 / (Ancho * scale))][(y1 / (Alto * scale))]->is_muro()) {
        move = false;
    }

    int collisionOffset = 50; // Píxeles de compensación para evitar la colisión

    for (QGraphicsItem* object : objects) {
        iterables* iterableObject = dynamic_cast<iterables*>(object);
        if (iterableObject && item->collidesWithItem(iterableObject)) {
            if (p_pal->isModoSigilo()) {
                if (p_pal->y() + p_pal->boundingRect().height() <= iterableObject->y()) {
                     p_pal->setgroundlevel(iterableObject->y() - p_pal->boundingRect().height());
                     move = true;
                }
            }else if (dir == 0 && iterableObject->x() < item->x()) {
                // Colisión desde la izquierda
                item->setPos(iterableObject->x() + collisionOffset, item->y());
                move = false;
            } else if (dir == 2 && iterableObject->x() > item->x()) {
                // Colisión desde la derecha
                item->setPos(iterableObject->x() - collisionOffset, item->y());
                move = false;
            }
        }
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
        case Qt::Key_Space:
            p_pal->ActualizarMovimiento(3);
            p_pal->move_jugador(3);
            break;
        case Qt::Key_A:
            p_pal->ActualizarMovimiento(0);
            if (ComprobarColision(p_pal, 0, Ancho_bloque_1, Alto_bloque_1)) {
                p_pal->move_jugador(0);
            }
            else{
                p_pal->setAceleracionx(0);
                p_pal->setAceleraciony(0);
                p_pal->setvelocityx(0);
                p_pal->setvelocityy(0);
            }
            break;
        case Qt::Key_D:
            p_pal->ActualizarMovimiento(2);
            if (ComprobarColision(p_pal, 2, Ancho_bloque_1, Alto_bloque_1)) {
                p_pal->move_jugador(2);
            }
            else{
                p_pal->setAceleracionx(0);
                p_pal->setAceleraciony(0);
                p_pal->setvelocityx(0);
                p_pal->setvelocityy(0);
            }
            break;
        case Qt::Key_E:
            for (size_t i = 0; i < puertas.size(); i++) {
                iterables* puerta = puertas[i];
                if (p_pal->collidesWithItem(puerta)) {
                    QPointF destino = destinos[i];
                    int piso = pisos[i];
                    int destinoX = static_cast<int>(destino.x());
                    int destinoY = static_cast<int>(destino.y() + 80);
                    p_pal->setfloor(piso);
                    p_pal->posicionar(destinoX, destinoY);
                    break;
                }
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



