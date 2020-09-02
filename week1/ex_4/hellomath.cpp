# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
    double x, y, z; 
    cin >> x;      
    cin >> y;
    cin >> z;
    cout << (x+y) - z << endl;
    return 0;
}