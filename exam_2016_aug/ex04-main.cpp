#include <iostream>
#include <string>
#include "ex04-library.h"

using namespace std;

int add(int u, int v){ return u + v; }
int substract(int u, int v){ return u - v; }

int main(void){
    
    Monoid<int> u(1);
    Monoid<int> v(2);
    Monoid<int> w(3);
    
  //  Monoid<int> x((u * v) * w);
    Monoid<int> x(u * (v * w));
    x.print(); cout << endl;
    cout << x.constants() << endl;

   // x.commute();
   // x.print(); cout << endl;
    for(unsigned int i=0;i<100000000;i++){
    x.associate_left();
    //x.print(); cout << endl;

    x.associate_right();
    //x.print(); cout << endl;
    }
    
    return 0;
}
