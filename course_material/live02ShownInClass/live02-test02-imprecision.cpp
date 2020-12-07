//============================================================================
// Name        : live02-test02-imprecision.cpp
// Description : Examples of arithmetic imprecision
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x=1.3232324423;
    double y=1.543454554;
    double z=0.500000089406967;

    cout << "x is " << x << " and y is " << y << endl;
    cout << "Is " << setprecision(20) << (x+y)/z << " equal to " << setprecision(20) << (x/z)+(y/z) << "?" << endl;

    if ((x+y)/z == (x/z)+(y/z)) {
        cout << "YES!" << endl;
    } else {
        cout << "NO!" << endl;
    }

    cout << "(0.1 + 0.2) - 0.3  is equal to... ";
    cout << (0.1 + 0.2) - 0.3 << endl;
}
