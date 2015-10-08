
#include <iostream>
using namespace std;

struct Punto {
double x,y;
};

int main() {
    int a=5;
    int *p=&a;
    Punto puntito= {2,3};

    Punto *point=new Punto{4,5};
    Punto *point2=&puntito;

    cout << point2->x <<endl;
     cout << point->x <<endl;

      cout << puntito.x <<endl;

      cout << (*point2).x <<endl;
       cout << (*point).x <<endl;

}
