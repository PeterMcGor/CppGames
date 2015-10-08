
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream F;
    F.open("tareas.txt");
    string w,l;
    while (F >> w >> l) {
        cout << w <<' '<< l;
    }
    F.close();
}
