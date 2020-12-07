//============================================================================
// Name        : live02-test07-choose.cpp
// Description : Implementation of the factorial and binomial (choose) functions
//============================================================================

#include <iostream>
using namespace std;

// Factorial function
int fact(int n)
{
    if (n <= 1) {
        return 1;
    }
    return n * fact(n-1);
}

// Choose implementation based on factorial
int choose1(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

// Choose implementation based on the multiplicative formula
int choose2(int n, int k)
{
    int result = 1;

    for (int i=1; i <= k; i = i+1) {
        double value = (n + 1 - i) / (double)i;
        result = result * value;
    }

    return result;
}

int main()
{
    int n, k;
    cout << "Please enter the value of n: ";
    cin >> n;

    cout << "Please enter the value of k: ";
    cin >> k;
    cout << "The result of choose1 is: " << choose1(n, k) << endl;

    cout << "The result of choose2 is: " << choose2(n, k) << endl;

    return 0;
}