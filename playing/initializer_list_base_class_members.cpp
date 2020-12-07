#include <iostream>

using namespace std;


class A{
	protected:
		int i;
	public:
		A(int);
};

A::A(int i): i(i){cout<< "A"<<endl;};

class B: private A{
	public:
		B(int);
		int getI();
};

B::B(int i): A(i){cout<<"B"<<endl;};
int B::getI(){return this->i;};


int main(){
	B b(1);
	cout <<b.getI()<<endl;
}
