#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main(){
    string buf;
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

}