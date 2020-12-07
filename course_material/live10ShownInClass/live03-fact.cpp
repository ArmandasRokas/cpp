// Simple recursive implementation of factorial
#include <iostream>
using namespace std;

double fact(double n){
    cout << "  fact(" << n << ") invoked" << endl;
    if (n == 0) {
        cout << "  end of recursion!  Returning 1" << endl;
        return 1;
    } else {
        cout << "  fact(" << n << ") = " << n << " * fact(" << (n-1) << ")" << endl;
        return n * fact(n - 1);
    }
}

int main(){
    double n;
    
    cout << "Give me a non-negative number: " ;
    cin >> n;
    cout << "Computing fact(" << n << ")... " << endl;
    double f = fact(n);
    cout << "The result is: " << f << endl;

    return 0;   
}
