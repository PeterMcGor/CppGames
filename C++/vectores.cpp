
#include <iostream>
#include <vector>
using namespace std;

void muestraVector(const vector <int>& v) {
    cout << '[';
    if (!v.empty()){
        cout << v[0];
    for (int i=1;i<v.size();i++) {
        cout << ','<<v[i];
    }
    }
    cout << ']';

}


vector <int> concat(const vector <int>& v1, const vector <int>& v2){
    vector <int> resul=v1;

    for (int i=0;i<v2.size();i++) resul.push_back(v2[i]);
    return resul;
}

int main () {
    vector <int> v(5,30),v2(3,2),v3;
    v.push_back(4);
    v2.push_back(1);
    v.resize(13);
    muestraVector(v);
    //cout<<endl;
    //muestraVector(v2);
    //cout << endl;
    v3=concat(v2,v);
    //muestraVector(v3);


}
