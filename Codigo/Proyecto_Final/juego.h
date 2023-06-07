#ifndef JUEGO_H
#define JUEGO_H

#define Ancho_Mapa 1344
#define Alto_Mapa 756
#define total_x_bloques 28
#define total_y_bloques 11

#include "jugador.h"
#include "mapas.h"
#include "iterables.h"
#include "enemigos.h"
#include "disparo.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <Qvector>
#include <QGraphicsView>
#include <QObject>
#include <cstdlib>
#include <QMessageBox>

class Juego : public QGraphicsScene
{
    Q_OBJECT
public:
    Juego();
    ~Juego();
private:
    Jugador *p_pal;
    Mapa *bl_mapa[total_x_bloques][total_y_bloques];
    iterables *interactuar;
    Enemigos *enemy;
    std::vector<iterables*> puertas;
    std::vector<QPointF> destinos;
    std::vector<int> pisos;
    std::vector<iterables*> objects;
    std::vector<Enemigos*> cant_enemy;
    int scale;
    void Agregar_Jugador();
    void Asignar_posicion_puerta();
    void Asignar_objeto();
    void actualizarEnemigos();
    void Agregar_objeto(int x, int y, int tipo);
    void Agregar_Puertas(int origenX, int origenY, int destinoX, int destinoY, int piso);
    void Asignar_posicion_enemigos();
    void agregarDisparo(Enemigos* enemy, Disparo* disparo);
    void manejarJugadorAlcanzado();
    void Agregar_Bala(int x, int y);
    void Agregar_Enemigos(int x, int y, bool movimiento);
    void crear_Mapa();
    QTimer *timerEnemigos;
    bool ComprobarColision(QGraphicsItem *item, short dir, int Ancho, int Alto);
    void centerViewOn(QGraphicsItem *item);
    void set_background(QString name, int scale);
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // JUEGO_H
