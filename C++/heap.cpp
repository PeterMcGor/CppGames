
#include <iostream>
using namespace std;

//Usar ne para guardar variables en heap

// 1. Para un tipo básico

// 2. Tabal básica

// 3. Para un struct

// 4. Una clase
class Circulo {
    double _radio,_cx,_cy;
public:
    Circulo(double r,double cx,double cy)
    : _radio(r),_cx(cx), _cy(cy) {}

    double radio() const {return _radio;}
};

struct Punto {double x,y;};
int main(){
    int T[10]; //Esto es reserva en la pila
    //1.
    int *p_entero = new int; // Puntero a un entero reservado
    *p_entero=3;
    cout << *p_entero << endl;

    //2.
    int *p_tabla = new int[10];
    *p_tabla = 1;
    *(p_tabla+3)=4;

    //3.
    Punto *p_punto= new Punto;
    p_punto->x=1.0;
    (*p_punto).y=2;
    //*p_punto.x

    // 4.
    Circulo *p_circulo = new Circulo(10,0,0);
    cout << p_circulo->radio() << endl;
    cout << (*p_circulo).radio()<<endl;


}
