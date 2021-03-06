// Recursive implementation of factorial in different styles
#include <iostream>
using namespace std;

// Recursive factorial (standard)
double fact(double n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n-1);
    }
}

// Recursive factorial (tail recursive using accumulator r)
double fact_tail(double n, double r = 1) {
    if (n == 0) {
        return r;
    }
    return fact_tail(n-1, n*r);
}

int main(){
    double n;
    
    // Try with with big numbers, e.g. 1000000
    // Compare compilation with and without optimization (-O3)
    cout << "Give me a non-negative double: " ;
    cin >> n;
    cout << "Computing fact_tail(" << n << ")..." << fact_tail(n) << endl;
    cout << "Computing fact(" << n << ")..." << fact(n) << endl;

    return 0;
}
