# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin
int sum(int n);

int main () // This the main entry of the program
{
    int input; 
    cin >> input;      
    // for loop
    cout << sum(input) << endl;
    return 0;
}
// Write recursive. 

int sum(int n){
    if(n>0){
        return n + sum(n-1); 
    } else{
        return 0;
    }
}

                        // sum(3) gives 6   
// return 3 + sum(2)   // sum(2) gives 3
// return 2 + sum(1)   // sum(1) gives 1
// return 1 + sum(0)   // sum(0) gives 0