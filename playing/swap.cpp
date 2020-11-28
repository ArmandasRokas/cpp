#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
	int a = 111;
	int b = 222;
	cout << "Before swap a: " << a << ", b: " << b << endl; 	
	int temp = a; // does not work with:  int& temp = a;
	a = b;
	b = temp; 
	cout << "After swap a: " << a << ", b: " << b << endl; 	
}
