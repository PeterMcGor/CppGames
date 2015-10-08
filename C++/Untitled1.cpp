
#include <iostream>
using namespace std;

int f(){
static int cont=0;
cont++;
}

int g(){
static int cont;
cont++;
}

int main() {
    for (int i=0;i<5;i++)
    cout << f()+g() << endl;

}
