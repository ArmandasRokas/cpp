// Example of stack overflow
#include <iostream>
using namespace std;

int depth = 1;

void f(){
    // int a[10000]; // Uncomment to accelerate stack overflow
    cout << "Depth " << depth << " reached...\n" ;
    depth++;
    f();
}

int main(){
    f();

    return 0;
}
