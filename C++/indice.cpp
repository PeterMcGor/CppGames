
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
    map < string,vector <int> > indice;
    ifstream fin ("TomSawyer.txt");
    vector <string> lineasLibro;
    string linea;

    while (getline(fin,linea)) {
        lineasLibro.push_back(linea);
    }

    //////////////////////////////////////
    //stringstream S;
   // string palabra;
    for (int i=0;i<lineasLibro.size();i++) {
        stringstream S(lineasLibro[i]);
        string palabra;
        while (S>>palabra) {
        indice[palabra].push_back(i);
        }
    }

    //////////////////////////////////////////

   map < string,vector<int> >::iterator it=indice.begin();
    for (int i=0 ;i<100;i++) {
        cout << it->first << " ";
        for (int j=0;j < it->second.size();j++ ) {
            cout<<" " << it->second[j];
        }
        cout << endl;
        it++;
    }


    string palabraBusc;
    cin >> palabraBusc;
    auto it2=indice.find(palabraBusc);
    if (it2 != indice.end()) {
    cout << it2->first << " ";
     for (int j=0;j < it2->second.size();j++ ) {
            cout<<" " << it2->second[j];
        }


    } else {
    cout << "No existe"<< endl;
    }





}
