#ifndef OBJETOS_H
#define OBJETOS_H
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <list>

using namespace std;

const float XTAM = 640 , YTAM = 480;
class Objeto {

    protected:
     float _x,_y,_a,_vx, _vy;

     public:
     Objeto(float x,float y);
     void mueve();
    void acelera();
    void rota (double da);

};

class Asteroide:public Objeto {
    float _tam;
    public:
    Asteroide (float x, float y);
    Asteroide (float x,float y,float tam,float vx,float vy);
    void pinta () const ;
    bool dentro (float x,float y) const;
    void explota(list<Asteroide*>& A) const;
};

class Misil:public Objeto {

public:
Misil(float x,float y,float a);
void pinta() const;
void mueve();
bool fuera() const;
bool choca(Asteroide* a) const;
};

class Nave:public Objeto{
    void vertices(float& x1, float& y1,
                  float& x2, float& y2,
                  float& x3, float& y3) const;

public:

    Nave(float x, float y) : Objeto(x,y){    };
    void pinta() const;
    bool choca (Asteroide* a) const;
    Misil *dispara() const;

};



#endif // OBJETOS_H
