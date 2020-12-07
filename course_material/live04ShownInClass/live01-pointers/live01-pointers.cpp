//============================================================================
// Name        : live01-pointers.cpp
// Description : Example on pointers, referencing and dereferencing
//============================================================================

#include <iostream>
using namespace std;


int main(){
    int x = 1;

    cout << "Variable x is residing in address " << (long)&x << endl;

    int *px = &x;

    cout << "The address pointed by px is: " << (long)px << endl;
    cout << "The value pointed by px is: " << *px << endl;

    *px = 42;

    cout << "The value pointed by px is now: " << *px << endl;

    cout << "The value of x is now: " << x << endl;

    // Experiments with & and *
    cout << "The value of variable x is " << x << endl;
    cout << "The value of variable x is " << *&x << endl;
    cout << "The value of variable x is " << *&*&x << endl;

    // Experiments with sizes of types
    cout << "An int in this computer uses " << sizeof(int) << " bytes" << endl;
    cout << "A double in this computer uses " << sizeof(double) << " bytes" << endl;

    double a[] = {3, 1, 2};
    cout << "The value   of a    is " << (long)a << endl;
    cout << "The address of a[0] is " << (long)&(a[0]) << endl;
    cout << "The address of a[1] is " << (long)&(a[1]) << endl;

    cout << "The value stored in the address pointed by a is " << *a << endl;
    cout << "The value stored in a[0] is " << *a << endl;

    return 0;
}
