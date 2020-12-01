#include <iostream>

using namespace std;

class Test{
	public:
		Test(){cout<< "Constructor is called"<<endl;}
		~Test(){cout<<"Destructor"<<endl;}
};

int main(){
	for(int i=0; i<3;i++){
		Test t;
	}
}
