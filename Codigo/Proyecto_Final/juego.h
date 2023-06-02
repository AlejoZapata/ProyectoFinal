#ifndef JUEGO_H
#define JUEGO_H

#include "jugador.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <Qvector>
#include <QObject>
#include <cstdlib>

class Juego : public QGraphicsScene
{
    Q_OBJECT
public:
    Juego();
    ~Juego();
private:
    Jugador *p_pal;
    void Agregar_Jugador();
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // JUEGO_H
