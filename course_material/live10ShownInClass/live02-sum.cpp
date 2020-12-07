// Sum of arithmetic series 1..n, i.e. 1+..+n
#include <iostream>
using namespace std;

// Smart implementation by Carl Friedrich Gauss (1777-1855) :-)
unsigned int sum_fast(unsigned int n){
    return (n * (n + 1)) / 2 ;
}

// Iterative implementation
unsigned int sum_iter(unsigned int n){
    unsigned int result = 0;
    for (unsigned int i = 1; i <= n; i++) {
        result = result + i;
    }
    return result;
}

// A recursive implementation
unsigned int sum_rec1(unsigned int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum_rec1(n - 1);
    }
}

// A tail-recursive implementation
unsigned int sum_rec2(unsigned int n, unsigned int acc = 0) {
    if (n == 0) {
        return acc;
    } else {
        return sum_rec2(n - 1, acc + n);
    }
}

int main(){
    unsigned int n;

    cout << "Give me a non-negative integer: " ;
    cin >> n;
    cout << "Computing sum(1.." << n << ") using sum_fast... ";
    cout << sum_fast(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_iter... ";
    cout << sum_iter(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec1... ";
    cout << sum_rec1(n) << endl;
    cout << "Computing sum(1.." << n << ") using sum_rec2... ";
    cout << sum_rec1(n) << endl;
    
    return 0;
}
