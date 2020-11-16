#include <string>
#include <vector>
#include <iostream>

using namespace std;


int main(void){
	int a = 10;
	int & b = a; // you can not change, where b refers to. It is permenent
	int c = 100;
	b = c; // changes the value of a to 100
	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
}
