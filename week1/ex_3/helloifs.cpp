# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
    int first, second;   
 //   cout << "Enter first number:" << endl;
    cin >> first;
 //   cout << "Enter second number:" << endl;
    cin >> second;
    if(first < second){
        cout << first << " is smaller than " << second << endl;
    } else if (first > second)
    {
        cout << first << " is bigger than " << second << endl;
    } else {
        cout << first << " is equal to " << second << endl;
    }
    return 0;
}