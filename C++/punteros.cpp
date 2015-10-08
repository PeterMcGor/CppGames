
#include <iostream>
#include <cmath>
using namespace std;



int main() {
    int a=5,b=10;
   // cout << int(&a) << endl;
   // cout << int(&b) << endl;     int *pa,*pb,*pAux;;
   a=a+b;
   b=a-b;
   a=a-b;
  int *pa = &a;
   int *pb = &b;
//   pAux=pb;
   *pb=*pa;
   pa=pa+pb;

  // pa=pa-1;
  //int dirB=0x(int(&a))+int(&b);

 // pb=dir;
//   pa=int(pa)+int(pb);

   //*pa=b;
   //*pb=a;

   cout << a << ' '<<b <<endl;

}
