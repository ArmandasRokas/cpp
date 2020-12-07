//============================================================================
// Name        : live07-eof.cpp
// Description : Two ways to detect the end-of-file (EOF) using cin >> var
//============================================================================

#include <iostream>
using namespace std;

int main() {
    cout << "To end your input, press either:" << endl;
    cout << "    * Enter and then CTRL+D (Linux, MacOS)" << endl;
    cout << "    * Enter and then CTRL+Z and then Enter (Windows)" << endl;

    string word;

    /*while (cin >> word) {
        cout << "The input was: " << word << endl;
    }*/

    // Alternative to the loop above
    // (If you use this, comment out the while loop above)
    
    bool keepReading = true;
    while (keepReading) {
        cin >> word;
        if (cin.fail()) {
            keepReading = false;
        } else {
            cout << "The input was: " << word << endl;
        }
    }
    
    
    cout << "EOF received!" << endl;
    
    return 0;
}
