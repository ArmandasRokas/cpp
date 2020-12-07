//============================================================================
// Name        : live02-test03-exponentiation.cpp
// Description : Three possible implementations of the exponentiation function (1. using math::pow, 2. recursive, 3. iterative)
//============================================================================

#include <iostream>
using namespace std;

#include <math.h>

double exp1(int a, int n);
double exp2(int a, int n);
double exp3(int a, int n);

int main()
{
    int a, n;

    cout << "Please enter the value of a: ";
    cin >> a;
    cout << "Please enter the value of n: ";
    cin >> n;

    cout << "Value of a^n using different methods" << endl;
    cout << "exp1: " << exp1(a, n) << endl;
    cout << "exp3: " << exp3(a, n) << endl;
    cout << "exp2: " << exp2(a, n) << endl;

    return 0;
}

double exp1(int a, int n)
{
    return pow((double)a, double(n));
}

// Recursive implementation
double exp2(int a, int n)
{
    if (n == 0) {
        return 1.0;
    }

    if (n < 0) {
        return 1.0 / exp2(a, -n);
    } else { // n > 0
        return a * exp2(a, n-1);
    }
}

// Iterative implementation
double exp3(int a, int n)
{
    double result = 1;
    double factor;

    if (n >= 0) {
        factor = a;
    } else {
        factor = 1.0 / a;
    }

    for (int i = 1; i <= abs(n); i = i+1) {
        result = result * factor;
    }

    return result;
}
