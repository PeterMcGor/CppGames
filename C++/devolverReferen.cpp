
#include <iostream>
using namespace std;

int& mayor(int& a,int& b) {
    if (a>b) {
        return a;
    } else {
        return b;
    }

}

int main() {
    int x,y;
    cin >> x >> y;
    mayor(x,y) = 3; //Mayor esta devolviendo una variable o x o y y le meto un 3 a la variable
    cout << x << ' '<< y << endl;

}
