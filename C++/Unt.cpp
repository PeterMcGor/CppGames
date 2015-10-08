#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main () {
     srand ( time(NULL) );

for (int i=0;i<1000;i++)
cout << rand() % 500 <<" ";

}

