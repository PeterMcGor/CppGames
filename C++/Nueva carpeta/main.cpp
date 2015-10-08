
#include "miniwin.h"
using namespace miniwin;

int main() {
   vredimensiona(400, 400);
   int tec = tecla();

  /* double y=2;
   double t=0;
   while (tec != ESCAPE) {
       borra();
    circulo_lleno(200,y,10);
    refresca();
    tec=tecla();
    espera(25);
    t++;
    y=y+0.5*9.8*t*t;
   }
   vcierra();*/

   int x=175;
   int y=392;
//  int mov=tecla();
   rectangulo_lleno(x,y,x+60,y+6);
    refresca();
    while (tec!=ESCAPE) {

        if (tec==IZQUIERDA && x >0) {
        borra();
        x-=10;
        rectangulo_lleno(x,y,x+60,y+6);
        refresca();
        }

        if (tec == DERECHA && x+60 < 400) {
             borra();
        x+=10;
        rectangulo_lleno(x,y,x+60,y+6);
        refresca();

        }

        tec=tecla();
    }


   vcierra();
   return 0;
}
