
#include <iostream>
using namespace std;

// Función.A partir del valor que se pasa se hace lo que sea y devuelve
// otra cosa pero no modifica el valor pasado por el programa princp.
int suma1(int n) {
    return n+1;
}

// Accion.Paso de un entero por referencia.El valor que se pasa en el
// programa que llama es el que se modifica.No se puede poner
// directamente el valor
void incrementa1(int& n){
    n=n+1;
}

int main () {
    int a=1,b=2,c;
    c=suma1(a);
    incrementa1(b);
    incrementa1(c);

    cout << c << ' ' << b << endl;
}
