# include <iostream> // This imports the library iostream ,
                    // which contains useful functions for
                    // reading and writing data
using namespace std ; // This allows us to use some ab br ev ia ti on s
                    // For example , we can write cin instead of std :: cin
void fact(int n);
bool firstTime = true;

int main () // This the main entry of the program
{
    int input; 
    cin >> input;      
    fact(input);
    return 0;
}

void fact(int n){
    if(n == 1){
        return;
    } else{
        if(firstTime){
            firstTime = false; 
        } else {
            cout << " * ";
        }
        int i;
        for(i = 2; i <= n; i++ ){
            if(n%i == 0){
                cout << i;
                break;
            }
        }
        fact(n/i);
    }
}
