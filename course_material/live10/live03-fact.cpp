// Simple recursive implementation of factorial
#include <iostream>
using namespace std;

double fact(double n){
    if (n == 0) {
        cout << "    fact(" << n << ") = 1.  End of recursion!" << endl ;
        return 1;
    } else {
        cout << "    fact(" << n << ") = " << n << " * fact(" << n-1 << ") " << endl;
        double ret = n * fact(n-1);
        cout << "    returning fact(" << n << ") = " << ret << endl;
        return ret;
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
