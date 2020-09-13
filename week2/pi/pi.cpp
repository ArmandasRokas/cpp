#include <cmath>
#include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin


int main () // This the main entry of the program
{
    int n; 
    cin >> n;      
    double res = 0.0;

    for(int i = 0; i<n; i++ ){
        res = res + pow(-1,i)/(2*i+1);
    }

    cout << 4*res << endl;
    return 0;
}
