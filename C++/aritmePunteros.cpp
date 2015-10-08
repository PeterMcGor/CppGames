
#include <iostream>
using namespace std;

int main() {
    double T[5] = {1,2,3,4,5};
    double *p;
    p=&T[0];
    //p=p+1;

    cout << *(p+1) << endl;
}
