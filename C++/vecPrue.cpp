
#include <vector>
#include <iostream>

using namespace std;

int main () {
    int cn;
    cin >> cn;
    vector <vector<int>> arbol(cn);

    for (int i=0; i < cn; i++) {
        arbol[i] = vector <int> (cn, INF);
    }


}
