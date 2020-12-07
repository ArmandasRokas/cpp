#include <iostream>

using namespace std;

class Parent{
	public:
		Parent(){
			cout<< "Parent constructor is called." << endl;
		}
};

class Child: public Parent{
	public:
		Child(){
			cout << "Child constructor is called." << endl;
		}
};

int main(){
	Child c;
}
