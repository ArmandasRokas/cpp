#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "test.h"
#include "fibonacci_tree.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int main(){
   /* string buf;
    getline(cin, buf);
    if(buf == ""){
        return 0;
    }
    std::istringstream ssin(buf);

    // declare input
    // vector<...> ... ;
    // ... input;
    while(ssin >> input){
        //.push_back(input);
    }
*/
    int n;
    cin >> n;
    FibonacciTree f(n);
    vector<int> values = f.get_values();
    int size = f.get_size();
    int depth = f.get_depth();
    int leafs = f.get_leafs();

    cout << "Call tree in pre-order: ";
    for(int i = 0; i < values.size(); i++){
            std::cout << values[i] << " ";
    }
    cout << endl;
    cout << "Call tree size: " << size << endl;
    cout << "Call tree depth: " << depth << endl;
    cout << "Call tree leafs: " << leafs << endl;
    //testDriver();
}