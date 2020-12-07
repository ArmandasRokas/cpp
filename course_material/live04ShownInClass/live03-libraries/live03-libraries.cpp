//============================================================================
// Name        : live03-libraries.cpp
// Description : Example on how to define and use libraries
//============================================================================

#include <iostream>
#include <string>
using namespace std;

// Here I include the header of my libary
#include "my_sweet_library.h"

int main(){

    string s;

    while(true) {
        cout << "Give me a word: ";
        cin >> s;

        // I use here a function of my sweet library
        cout << sweet(s) << endl;
    }

    return 0;
}
