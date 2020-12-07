//============================================================================
// Name        : live01-allocation-stack-heap.cpp
// Description : How are vectors and arrays allocated? With solutions
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

// See: http://www.learncpp.com/cpp-tutorial/79-the-stack-and-the-heap/

/*
int *createArrayBAD() {
    int a[2];
    a[0] = 1;
    a[1] = 2;
    return a;
}
*/

int *createArrayGOOD() {
    int *a = new int[2];
    a[0] = 1;
    a[1] = 2;
    return a;
}

int main(){
    int x = 1;
    cout << "The value of x is: " << x << endl;
    {
        int x = 22;
        cout << "The value of x is: " << x << endl;
        {
            int x = 333;
            cout << "The value of x is: " << x << endl;
        }
        cout << "The value of x is: " << x << endl;
    }
    cout << "The value of x is: " << x << endl;
}
