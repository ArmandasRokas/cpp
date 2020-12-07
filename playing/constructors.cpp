#include <iostream>

using namespace std;

class A{
	public:
		A(){
			cout << "A constructor" << endl;
		};
		int i;
};

class B{
	private:
		A a;
	public:
		B(){
			cout << "B constructor" << endl;
		}
		int getI(){return a.i;};
};

int main(){
	B b;
	cout <<"b.i: " <<  b.getI() << endl;
}
