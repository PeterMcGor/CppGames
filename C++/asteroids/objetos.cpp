#include "objetos.h"
#include "utils.h"
#include <cmath>
#include "miniwin.h"

using namespace std;
using namespace miniwin;






Objeto::Objeto(float x,float y) {
    _x=x;
    _y=y;
    _a=0;
    _vx=0;
    _vy=0;
}

void Objeto::mueve () {
      _x += _vx ;
      _y += _vy ;

   limites(_x,XTAM);
   limites(_y,YTAM);

}

void Objeto::acelera () {
    float ax=0,ay=-0.15;
           rotar(ax,ay,0,0,_a); // Vector aceleracion en la direción de la nave
           _vx += ax;
           _vy += ay;

}

void Objeto::rota (double da) {
    _a += da;

}

Asteroide:: Asteroide (float x, float y) : Objeto(x,y) {
        _tam=32;
        _vx = 0.2 * pow(-1,rand());
        _vy = 0.2 * pow(-1,rand());
    };


Asteroide::Asteroide (float x,float y,float tam,
                      float vx,float vy)
    : Objeto(x,y)
    {
        _tam =tam;
        _vx=vx;
        _vy=vy;
    }



void Asteroide::pinta () const {circulo(_x,_y,_tam);}
bool Asteroide::dentro (float x,float y) const {
    float dx = x - _x, dy = y - _y;
    return sqrt(dx*dx + dy*dy) < 32;
}

void Asteroide::explota(list<Asteroide*>& A) const {
    if (_tam > 30 ) {
        for (int i = 0; i < 4; i++) {
        float vx = _vx + 0.1 * pow(-1,rand());
        float vy = _vy + 0.1 * pow(-1,rand());
        A.push_back(new Asteroide(_x,_y,16,vx,vy));
        }
    }
}



void Nave::vertices(float& x1, float& y1,
                    float& x2, float& y2,
                    float& x3, float& y3) const {
    x1 = _x; y1 = _y-40;
    x2 = _x-15;y2 = _y +10;
    x3 = _x +15;y3 = _y +10;
    rotar(x1, y1, _x, _y, _a );
    rotar(x2, y2, _x, _y, _a );
    rotar(x3, y3, _x, _y, _a );
}

void Nave::pinta() const {
    float x1 = _x  , y1 = _y-40;
    float x2 = _x-15,y2 = _y +10;
    float x3 = _x +15,y3 = _y +10;
    rotar(x1, y1, _x, _y, _a );
    rotar(x2, y2, _x, _y, _a );
    rotar(x3, y3, _x, _y, _a );


    linea(x1,y1,x2,y2);
    linea(x1,y1,x3,y3);
    linea(x2,y2,x3,y3);

}

bool Nave::choca(Asteroide* a) const {
    float x1, y1, x2, y2, x3, y3;
    vertices(x1, y1, x2, y2, x3, y3);
    return a->dentro(x1,y1) || a->dentro(x2,y2) || a->dentro(x3,y3);
}

Misil * Nave::dispara() const {
     float x1, y1, x2, y2, x3, y3;
    vertices(x1, y1, x2, y2, x3, y3);
    return new Misil(x1,y1,_a);
}

Misil::Misil(float x,float y,float a)
 : Objeto(x,y)
 {
     _a = a;
     _vx = 0;
     _vy = -5;
     rotar (_vx,_vy,0,0,_a);
 }

 void Misil::pinta() const {

     float x1 = 0, y1 = -5, x2 = 0, y2 = 5;
     rotar(x1,y1,0,0,_a);
     rotar(x2,y2,0,0,_a);
     linea(x1+_x, y1+_y, x2+_x, y2+_y);
 }

void Misil::mueve () {
      _x += _vx ;
      _y += _vy ;

}

bool Misil::fuera() const {
 return _x > XTAM || _x < 0 || _y > YTAM || _y < 0;
}

bool Misil::choca(Asteroide* ast) const {
  float x1 = 0, y1 = -5, x2 = 0, y2 = 5;
     rotar(x1,y1,0,0,_a);
     rotar(x2,y2,0,0,_a);
     return ast->dentro(x1+_x,y1+_y) || ast->dentro(x2+_x,y2+_y);
}
