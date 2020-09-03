# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
    int input, x=0;  // Warning. Must be initialized with 0, otherwise it is assign to the random value. 
    cin >> input;      
    // for loop
    int i;
    for (i = 0; i <= input; i=i+2)
    {
        x = x + i;
    }
    cout << x;
    return 0;
}