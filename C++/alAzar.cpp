
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main() {
int N;
string fileName;
cout << "cuantos números?" << endl;
cin >> N;
cout << "nombre del fichero" << endl;
cin >> fileName;

ofstream fout;
srand(time(0));
fout.open(fileName.c_str());
for (int i=0;i<N;i++) {
    fout<<rand() << ' ';
}
fout.close();



}
