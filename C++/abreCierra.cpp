
#include <iostream>
#include <vector>
using namespace std;

int buscaCarac(const vector<char>& v,char c,int pos,int);
int primerCoin(const vector<char>& v, const char *caracteres,int pos) {
   int actual=buscaCarac(v,caracteres[0],pos,0);;
   int minimo=actual;
    for (int i=1; caracteres[i] != '0';i++) {
        actual=buscaCarac(v,caracteres[i],pos,0);
        if (actual<minimo  ) minimo=actual;

    }
    return minimo;
}


int buscaCarac(const vector<char>& v,char c,int pos,int posFin) {
    for (int i=pos;i<=posFin;i++) {
        if (v[i]==c) return i;
    }

    return -1;
}

char pareja(char c) {
    char pair;
    switch(c) {
        case '[':
            pair=']';
            break;
        case '(':
               pair=')';
               break;
        default:
               pair='}';
    }

    return pair;
}

int main () {

    char c;
    vector<char> ristra;

    cin >> c;

    while (c!='0')   {
        ristra.push_back(c);
        cin >> c;
    }
   ristra.clear();
   ristra={'[','(',']','{','(','[','}','(','(',']'};
    char car[]= {'(','[','{','0'};

   int abre=0,cierra=ristra.size();
    for(;abre<ristra.size();) {
    while (abre<cierra) {
        abre=primerCoin(ristra,car,abre);
        cierra=buscaCarac(ristra,pareja(ristra[abre]),abre,cierra);
        if (cierra!=-1) {
            cout<< ristra[abre] << ' ' << ristra [cierra];
            abre++;
            cierra--;
        } else {abre=cierra;}

    }
    abre=cierra+1;
    cierra=ristra.size();
    }







  /*  for (int i=0;i<ristra.size();i++) cout<<ristra[i];
    cout<<endl;

   cout << primerCoin(ristra,car,0) << endl;

    cout<< buscaCarac(ristra,'a',0);
    cout<< pareja('(');*/



}
