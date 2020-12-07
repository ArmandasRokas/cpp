// Name        : live01-types.cpp
//============================================================================
// Description : Simple example on types, mixed data types, and casting
//============================================================================

#include <iostream>
#include <typeinfo>

using namespace std;

int main(void){

    // The type of an expression can be
    // obtained with typeid(expression).name()
    // For example...
    cout << "The type of 3.14 is " << (typeid(3.14)).name() << endl;
    cout << "The type of 3.14f is " << (typeid(3.14f)).name() << endl;
    cout << "The type of 9/6 is " << (typeid(9/6)).name() << endl;
    cout << "The type of 9/(float)6 is " << (typeid(9/(float)6)).name() << endl;

    return 0;
}
