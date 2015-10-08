
#include <iostream>
using namespace std;

int main () {

int a=5,b=2;
int *p=&a; //'p' apunta a 'a'
p=&b;      //'p'apunta a 'b'
*p=3;
cout << b << endl;
}
