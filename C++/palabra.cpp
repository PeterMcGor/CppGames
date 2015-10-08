
#include <iostream>
using namespace std;

int main () {
string palabraNueva="palabra",palPri="zzzz";
int contador,comparador=1000;


while (palabraNueva != "."){
    contador=0;

    while (contador>=0) {
        comparador=int(palabraNueva[contador])-int(palPri[contador]);
        if (comparador<0) {
            palPri=palabraNueva;
            contador=-1;
        } else if(comparador>0) {
            contador=-1;
        } else { contador ++;}


    }
   cin >> palabraNueva;

}



cout<< "LA primera es: "<<palPri<< endl;
}
