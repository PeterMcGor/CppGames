
#include <iostream>
#include <list>
using namespace std;

void muestraLista (const list<char>& lista) {
    list<char>::const_iterator it= lista.begin();
    for ( ; it!=lista.end(); it++) {
      cout << *it;
    }
    cout << endl;
}

int main() {

    list <char> L;
    for (int i=0;i<26;i++) {
        L.push_back(char(int('a')+i));
    }
    muestraLista(L);

}
