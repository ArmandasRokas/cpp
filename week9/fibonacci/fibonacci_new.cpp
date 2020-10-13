#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int fibonacci(int n);

int main(){
    string buf;
    getline(cin, buf);
    if(buf == ""){
        return 0;
    }
    std::istringstream ssin(buf);

    // declare input
    vector<int> nums ;
    int input;
    while(ssin >> input){
        nums.push_back(input);
    }

    for(int num: nums){
        int fib = fibonacci(num);
        cout << fib << " ";
    }
    cout << endl;
}

int fibonacci(int n){
    if(n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}



