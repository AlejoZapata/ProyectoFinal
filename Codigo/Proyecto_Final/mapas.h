#ifndef MAPA_H
#define MAPA_H

#define Ancho_bloque_1 24
#define Alto_bloque_1 32

#include <QGraphicsScene>
#include <vector>
#include <QGraphicsRectItem>

class Mapa : public QObject, public QGraphicsPixmapItem
{
public:
    Mapa();
    ~Mapa();
    void CrearMuros(int Nivel);
    void is_wall(int x);
    bool is_muro();
private:
    int numPlantas, alturaPlanta, is_a_wall;;
    QPixmap *Muro_prision;
    QPixmap *Fondo1;
    void setImagen();
    int scale;
};

#endif // MAPA_H
