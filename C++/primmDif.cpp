
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ifstream F;
    ofstream O("largo.txt");
    F.open("tareas.txt");
    int w,l;
    vector <int> pesos,largo,resta;
    map <int,int> restInd;
    while (F >> w >> l) {
        pesos.push_back(w);
        largo.push_back(l);
    }
    F.close();

    for (int i=0;i<pesos.size();i++) {
        resta.push_back( pesos[i] - largo[i]);
    }

    for (int i=0;i<resta.size();i++) {
        restInd[i] = resta[i];

    }



}
