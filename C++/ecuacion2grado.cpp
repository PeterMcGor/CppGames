
#include <iostream>
#include <cmath>
using namespace std;

void ecua2grado(double a,double b,double c,
                double& x1, double&x2, int& nSol)
{
    double disc= b*b - 4*a*c;
    if (disc==0) {
        nSol=1;
        x1=-b/(2*a);
        } else if (disc < 0) {
            nSol = 0;
        } else {
            nSol=2;
            x1 = (-b + sqrt(disc)) / (2*a);
            x2 = (-b - sqrt(disc)) / (2*a);
        }

                }


int ecua2grado2(double a,double b,double c,
                double& x1, double&x2)
{
    int nSol;
    double disc= b*b - 4*a*c;
    if (disc==0) {
        nSol=1;
        x1=-b/(2*a);
        } else if (disc < 0) {
            nSol = 0;
        } else {
            nSol=2;
            x1 = (-b + sqrt(disc)) / (2*a);
            x2 = (-b - sqrt(disc)) / (2*a);
        }

        return nSol;

                }



int main() {
 double a,b,c;
 cin >> a >> b >>c;
 double s1,s1a,s2,s2a;
 int nS,nS2;

 // La accion modificara el valor de s1,s2,nS pero no de los
 // parametros
 ecua2grado(a,b,c,s1,s2,nS);
 nS2=ecua2grado2(a,b,c,s1a,s2a);

 if (nS== 0) {
    cout<<"No hay soluciones"<<endl;

 } else if (nS == 1) {
 cout << s1 << endl;
 } else {
 cout << s1 <<" "<< s2 << endl;
 }

 if (nS2== 0) {
    cout<<"No hay soluciones2";

 } else if (nS2 == 1) {
 cout << s1a << " 2"<<endl;
 } else {
 cout << s1a <<" "<< s2a <<" 2"<< endl;
 }

 }
