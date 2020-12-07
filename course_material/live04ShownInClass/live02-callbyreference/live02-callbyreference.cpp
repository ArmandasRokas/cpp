//============================================================================
// Name        : live02-callbyreference.cpp
// Description : Example on passing values by reference
//============================================================================

#include <iostream>
using namespace std;

// swap that does not work
void swapWrong(int px, int py) {
    int z;

    z  = px;
    px = py;
    py = z;
}

// swap in indirect call-by-reference
// i.e. call-by-reference using pointers
void swapWithPointers(int *px, int *py) {
    int z;

    z  = *px;
    *px = *py;
    *py = z;
}

// swap in call-by-reference style
void swapByReference(int &x, int &y) {
    int z;

    z = x;
    x = y;
    y = z;
}

int main(void) {
    int a, b;

    a = 1;
    b = 2;
    cout << "Initial values" << endl;
    cout << "a,b = " << a << "," << b << endl;

    cout << "Wrong swap" << endl;
    swapWrong(a, b);
    cout << "a,b = " << a << "," << b << endl;

    cout << "Swapping by reference (via pointers)" << endl;
    swapWithPointers(&a, &b);
    cout << "a,b = " << a << "," << b << endl;

    cout << "Swapping by reference" << endl;
    swapByReference(a, b);
    cout << "a,b = " << a << "," << b << endl;
}
