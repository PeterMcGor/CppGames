
#include <iostream>
using namespace std;

struct Eslabon {
int num;
Eslabon *anterior;
};

int main () {
    int n;

    Eslabon *ant=0;
    cin >> n;
    while(n!=0) {
      Eslabon *actual = new Eslabon;
      actual -> num = n;
      actual -> anterior=ant;
      ant=actual;
      cin >> n;
    }

    while (ant!=0) {
    cout << ant->num << " ";
    ant=ant->anterior;
    }


}
