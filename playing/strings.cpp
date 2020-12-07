#include <iostream>

using namespace std;

int main(){
	string test = "testing";
	char& a = test[0];
	cout << a << endl;	
        a = 'n';
	swap(test[1], test[2]);
	cout << test << endl;
}
