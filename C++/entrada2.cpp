
#include <iostream>
#include <fstream>
using namespace std;

int main() {
ifstream fin("datos1.txt");
string nombre;
int edad;

fin >> nombre >> edad;
cout << "Nombre: " << nombre <<" "<< "Edad: " << edad << endl;;
}
