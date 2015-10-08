
#include "miniwin.h"

#include <list>
#include <cstdlib>
#include <time.h>
#include <sstream>
#include "objetos.h"

using namespace std;
using namespace miniwin;


class Juego {
      list <Asteroide*> asteroides;
      list <Misil*> M;
       Nave N;
       bool _gameOver;
public:
    Juego();
    bool gameOver() const {return _gameOver;}
    void movimiento();
    void hostias();
    void tecla(int t);
    void repinta() const;

};

Juego::Juego()
: N(XTAM/2,YTAM/2) {
    srand ( time(NULL) );
     vredimensiona(XTAM, YTAM);


   for (int i = 0;i <5 ;i++) {
    asteroides.push_back(new Asteroide(rand()%500 , rand()%500));
   }

    _gameOver =  false;
}

void Juego::movimiento () {
           N.mueve();
           // lo del auto te quits poner todo el tipo
           for (auto it=asteroides.begin(); it != asteroides.end(); it++) {
            (*it)->mueve();
           }
           auto itm = M.begin();
           for (; itm != M.end();itm++) {
            (*itm)->mueve();
           }
           itm = M.begin();
           while ( itm != M.end()) {
           if ( (*itm)-> fuera() ) {
                delete (*itm);
                itm =  M.erase(itm); // para no perder hilo de la lista
           } else {
            itm++;
           }
           }

}

void Juego::hostias() {

    // Hostiones
      for (auto it=asteroides.begin(); it != asteroides.end(); it++) {
        if (N.choca(*it)) {
            _gameOver = true;
        }
       }

       //Colisiones para misisles y asterois

       auto itm = M.begin();
       while ( itm != M.end()) {
           //Asteroide con misil
           auto ita = asteroides.begin();
           while (ita != asteroides.end() && !(*itm)->choca(*ita)) {
            ita++;
           }
            if (ita != asteroides.end()) {
            delete *itm;
                itm = M.erase(itm);
                (*ita)->explota(asteroides);
                delete *ita;
                ita = asteroides.erase(ita);
            } else {
                itm++;
            }
       }
}

void Juego::tecla(int t) {
      //TEclas
       if (t == DERECHA) {
        N.rota(-10);
       }else if(t == IZQUIERDA) {
        N.rota(10);
       } else if ( t == ARRIBA) {
           N.acelera();
       } else if (t == ESPACIO) {
        // disparo
        M.push_back(N.dispara());
       }
}

void Juego::repinta() const {
     borra();
     for (auto it=asteroides.begin(); it != asteroides.end(); it++) {
         //(*it)->mueve();
        (*it)->pinta();
       }

      for (auto itm = M.begin(); itm != M.end();itm++) {
        (*itm)->pinta();
       }

    N.pinta();

    stringstream S;
    S << M.size() << ' '<< asteroides.size();
    texto(20,20,S.str());

    refresca();

}

int main() {
    Juego J;

   int t = tecla();
      while (t != ESCAPE  ) {
    if (!J.gameOver()) {
      J.movimiento();
      J.hostias();
      J.tecla(t);
      }
      J.repinta();

    espera(5);
    t = tecla();
   }

   vcierra();

   return 0;
}
