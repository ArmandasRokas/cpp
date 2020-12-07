#include <iostream>

using namespace std;

class A{
	private:
		int i;
	public:
		A(int);
		int getInt();
};

A::A(int i){
	this->i = i;
	cout << "A constructor" << endl;
}

int A::getInt(){
	return this->i;
}

class B{
	private:
		A a;
	public:
		B(int);
		int getInt();
};
B::B(int i): a(i){
	cout << "B constructor" << endl;
};
int B::getInt(){
	return a.getInt();
}

int main(){
	B b(1);
	cout << b.getInt() << endl;
	return 0;
}
