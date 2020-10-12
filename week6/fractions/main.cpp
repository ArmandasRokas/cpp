#include <iostream> 
#include <string>
#include <sstream>
#include <vector>
#include "Fraction.h"

using std::cin; 
using std::cout;                 
using std::string;
using std::vector;

using namespace std ; // This allows us to use some abbreviations
// For example , we can write cin instead of std :: cin

void performOperations(std::istringstream &ssin, Fraction & f);


int numerator;
int denominator;
char seperator;
string sign;

int main () // This the main entry of the program
{
    // Read from console
    string buf;
    // std::vector<string> bufs;
    // while(getline(cin, buf)){
    //         bufs.push_back(buf);
    // }

    // for(int i = 0; i <bufs.size() ; i++){
    //     cout << "From cout: " << bufs[i] << endl;
    // }





    while(getline(cin, buf)){
        // Initialize first fraction
        std::istringstream ssin(buf);
        ssin >> numerator;
        ssin >> seperator;
        ssin >> denominator;
        Fraction f = Fraction(numerator,denominator);
        performOperations(ssin, f);
        f.display();
    }


    

    return 0; // This is used to signal correct termination (0)
}

void performOperations(std::istringstream &ssin, Fraction & f){
        while(ssin >> sign){
            ssin >> numerator;
            ssin >> seperator;
            ssin >> denominator;
            Fraction f2 = Fraction(numerator,denominator);
            
            if(sign == "+" ) {
                f.add(f2);
            } else if (sign == "*"){
                f.mult(f2);
            } else {
                f.div(f2);
            }
    }
}