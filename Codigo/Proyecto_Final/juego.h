#ifndef JUEGO_H
#define JUEGO_H

#define Ancho_Mapa 1344
#define Alto_Mapa 756
#define total_x_bloques 28
#define total_y_bloques 11

#include "jugador.h"
#include "mapas.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <Qvector>
#include <QGraphicsView>
#include <QObject>
#include <cstdlib>

class Juego : public QGraphicsScene
{
    Q_OBJECT
public:
    Juego();
    ~Juego();
    bool ComprobarColision(QGraphicsItem *item, short dir, int Ancho, int Alto);

private:
    Jugador *p_pal;
    Mapa *bl_mapa[total_x_bloques][total_y_bloques];
    int scale;
    void Agregar_Jugador();
    void crear_Mapa();
    void centerViewOn(QGraphicsItem *item);
    void set_background(QString name, int scale);
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // JUEGO_H
