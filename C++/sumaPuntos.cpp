
#include <iostream>
using namespace std;

struct Punto {
    double x,y;
};

// PAsan como referencias constates para no copiarlos pero no modificarlos
Punto operator+(const Punto& p1,const Punto& p2) {
    Punto res;
    res.x= p1.x +p2.x;
    res.y = p1.y+p2.y;
    return res;

}

ostream& operator<< (ostream& o,const Punto& p) {
    return o << '(' << p.x << ", " << p.y << ')';

}

// en este se modifica el primer parametro
void operator+=(Punto& p,const Punto otro) {
    p.x+=otro.x;
    p.y+=otro.y;
}

Punto operator*(const Punto& p,double factor) {
Punto res;
res.x=p.x * factor;
res.y=p.y * factor;
return res;
}

void showPunto(const Punto& p) {
    cout << '(' << p.x << ", " << p.y << ')';

}

Punto sumPuntos(const Punto& p1,const Punto& p2) {
    Punto res;
    res.x=p1.x+p2.x;
    res.y=p1.y+p2.y;
    return res;
}

void incPunto(Punto& p,const Punto& otro) {
p.x+=otro.x;
p.y+=otro.y;
}

Punto mulPunto(const Punto& p,double factor) {
    Punto res;
    res.x=p.x*factor;
    res.y=p.y*factor;
    return res;

}

int main() {
    Punto p1={0,5},p2={5,0},p3={1,1},p4;
    /*p4 = p1 + p1 + p2;  // operator+(p1,p2) Redefinición
    p4+=p3;
    cout << p4*0.5 << endl;*/

   // Igual pero con funciones típicas
   p4= sumPuntos((sumPuntos(p1,p1)),p2);
    incPunto(p4,p3);
    showPunto(mulPunto(p4,0.5));
    cout <<  endl;

}
