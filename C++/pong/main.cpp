#define _WIN32_WINNT 0x0501
#include <windows.h>

#include "miniwin.h"
using namespace miniwin;

const int pantX = 600;
const int pantY = 400;
const int tamR = 5;



class Objeto {
    float _posX,_posY,_tam,_alto;
    double _vX,_vY;

    public:
    Objeto();
    Objeto(float x,float y,float tamanio);
    void mueve (double dx,double dy) ;

    // geters
    float getX () const {return _posX;}
    float getY () const {return _posY;}
    float getTam () const {return _tam;}
    float getAlto() const {return _alto;}
    double getVX () const {return _vX;}
    double getVY () const {return _vY;}

    // setters

    void setX(float x) {_posX=x;}
    void setY(float y) {_posY=y;}
    void setTam(float t) {_tam=t;}
    void setVX(double vx) {_vX=vx;}
    void setVY(double vy) {_vY=vy;}
    void setAlto(float alto) {_alto=alto;}

    virtual void pinta() const{} ;


};

Objeto::Objeto(float x,float y,float tamanio) {
   _posX=x;
   _posY=y;
   _tam=tamanio;
   _vX=0;
   _vY=0;
   _alto=0;

}

void Objeto::mueve (double dx,double dy) {

        if (dx<0) {
            if (_posX-getAlto()>0 ) _posX+=dx;

        } else { // Desde aqui caso de positivos
            if (_posX+getAlto()<pantX) _posX+=dx;
        }

        // Para las y's
        if  (dy<0) {
            if (_posY-getAlto() > 0) _posY+=dy;

        } else { //y's positivas
            if (_posY+getAlto()<pantY) _posY+=dy;
        }

    }


class Raqueta : public Objeto {
    int points;


public:
    Raqueta(float x,float y,float tamanio) : Objeto(x,y,tamanio) {setAlto(tamanio*6); setVX(0);setVY(7);}
        void pinta() const { rectangulo_lleno(getX()-tamR,getY()-getAlto(),getX()+tamR,getY()+getAlto()); }

};

class Pelota : public Objeto {

    public:
        Pelota(float x,float y,float radio) : Objeto(x,y,radio) {setAlto(radio);setVX(1);}
        void pinta() const { circulo_lleno(getX(),getY(),getTam());}
        void rebota(){ if ( (getY()-getTam() <= 0) || (getY()+getTam() >= pantY) ) setVY(- getVY()); }
        int punto() const;
        void coincide (Raqueta& r,int mov) ;


};

int Pelota::punto() const {
    if ( getX() - getTam()<=0) return -1;
    if ( getX()+ getTam() >= pantX) return 1;
    return 0;
}

void Pelota::coincide(Raqueta& r ,int mov)  {
    static int state=1;
    if (state ==1) {
    if ( getX()+getTam() >= r.getX()-r.getTam() && getY()>= r.getY()-r.getAlto() && getY() <=r.getY()+r.getAlto())  {
        if (mov>0) setVY(getVY()+0.25*r.getVY());
        setVX(-getVX());
        state*=-1;
        }
    } else {
        if ( getX()-getTam() >= r.getX()+r.getTam() && getY()>= r.getY()-r.getAlto() && getY() <=r.getY()+r.getAlto())  {
        if (mov>0) setVY(getVY()+0.25*r.getVY());
        setVX(-getVX());

         state*=-1;
    }

    }

}




int main() {
   int movimiento=0;
   vredimensiona(pantX, pantY);
   Raqueta J1 (pantX-10,pantY/2,tamR);
   Raqueta J2 (10,pantY/2,tamR);
//   Raqueta J2;
   int t=tecla();
   //int a=int('a'),b=int('b');
    J1.pinta();
    J2.pinta();

  Pelota *pP = new Pelota(pantX/2,pantY/2,6);
   pP->pinta();
   refresca();
   pP->setVY(4);
   pP->setVX(4);





   while (t != ESCAPE) {

      // J1.setVY(0);
        if (GetAsyncKeyState(VK_RIGHT)) {

        J1.setVY(-10);
        J1.mueve(0,-10);
        movimiento=50;
        }
        if (GetAsyncKeyState(VK_LEFT)) {
        J1.setVY(10);
        J1.mueve(0,10);
        movimiento=50;
         }
          if (GetAsyncKeyState(VK_LCONTROL)) {
             J2.setVY(10);
           J2.mueve(0,10);
           movimiento=50;
         }
          if (GetAsyncKeyState(VK_LSHIFT)) {
             J2.setVY(-10);
             J2.mueve(0,-10);
             movimiento=50;

         }



    pP->coincide(J1,movimiento);
  // pP->coincide(J2,movimiento);
    if(pP->punto()== -1){pP->setVX(- pP->getVX()); }
    if(pP->punto()== 1){pP->setVX( - pP->getVX()); }
    borra();
    pP->rebota();
   pP->mueve(pP->getVX(),pP->getVY());
   J1.pinta();
   J2.pinta();
   pP->pinta();
   refresca();
   t=tecla();
  if (movimiento>0) movimiento--;
   espera(50);

   }





  /* while (t != ESCAPE) {
    if (GetAsyncKeyState(VK_LEFT)) {
        borra();
        J1.setVY(7);
        J1.mueve(0,J1.getVY());

        J1.pinta();
        refresca();
    }

    if (GetAsyncKeyState(VK_RIGHT)) {
        borra();
        J1.setVY(-7);
        J1.mueve(0,J1.getVY());
        J1.pinta();
        refresca();

    }
    espera(25);
    t=tecla();
   }*/

   vcierra();




   return 0;
}
