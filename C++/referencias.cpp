
#include <iostream>
using namespace std;

struct Punto{
    float x,y;
};

struct ListaPuntos {
    Punto puntos[100];
    int nPuntos;

};

int main(){
    ListaPuntos L;
    L.nPuntos=50;
    float& x=L.puntos[L.nPuntos-1].x; // Trabajo con x y no con todo el chorizo
    x = x+2;

    Punto origen = {0,0};
    float& _x=origen.x;

}
