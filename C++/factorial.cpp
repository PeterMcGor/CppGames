
#include <iostream>
using namespace std;

int main() {
    int N,resultado;
    cout << "Números: " ;
    cin >> N;
    resultado=N;

    while (N>=2) resultado *= --N;


    cout<< "factorial: " << resultado;

}
