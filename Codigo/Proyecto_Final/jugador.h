#ifndef JUGADOR_H
#define JUGADOR_H

#define Ancho_jugador_up 24
#define Alto_jugador_up 32
#define Ancho_jugador_down 40
#define Alto_jugador_down 36
#define Pos_sprite_Jugador_x 40
#define Pos_sprite_Jugador_y 6
#define total_sprites_jugador 3
#define col_sprite 16
#define filas_sprite 4
#define impx 8
#define impy 180

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Jugador : public QGraphicsPixmapItem, public QObject
{
public:
    Jugador();
    ~Jugador();
    int cant_sprites;
    void move_jugador(int type);
    void ElegirSprite(int x, int y);
    void setImage();
    void posicionar(int x, int y);
    void ActualizarMovimiento(int type);
    void setAceleracionx(int aceleracionX);
    void setAceleraciony(int aceleracionY);
    void setvelocityx(int velocityx);
    void setvelocityy(int velocityy);
    void setfloor(int piso_act);
    void setmodoSigilo();
    int getgroundlevel();
    void setgroundlevel(int pix);
    bool isModoSigilo();
private:
    QPixmap *Personaje, *Movimiento;
    qreal velocityY, velocityX;
    qreal scale;
    qreal posx, posy, T, delta;
    void cinematica();
    bool isJumping, modoSigilo;
    void jump();
    int groundLevel;
    int aceleracionx, aceleraciony, currentFloor;
    std::vector<qreal> groundLevels;
    QTimer *timer;
    void applyGravity();
};



#endif // JUGADOR_H
