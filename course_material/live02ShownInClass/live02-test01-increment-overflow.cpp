// Name        : test01-increment-overflow.cpp
//============================================================================
// Description : Examples illustrating arithmetic overflows
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int increment(int x)
{
    // cout << "*** Increment has been called!" << endl;
    return x+1;
}

int safe_increment(int x)
{
    // Hi!
    if (((double)x + 1.0) > (double)INT_MAX) {
        cout << "WARNING: overflow!" << endl;
    }

    return x+1;
}

int main()
{
    int n;
   
    cout << "The maximum value of an integer is: " << INT_MAX << endl;
    cout << "The minimum value of an integer is: " << INT_MIN << endl;
    cout << "Please give me the value of n: ";
    cin >> n;
    
    cout << "If we increment n, we get: " << safe_increment(n) << endl;

    return 0;
}