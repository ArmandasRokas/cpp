#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Test{
	public: 
		string s;
		Test() {}
		
		Test(const Test &t){
		cout << "Copy constructor called" << endl;
		}

		Test& operator= (const Test &t){
			this->s = t.s;
			cout << "Assignment operator called" << endl;		
			return *this;
		}

};

int main(void){
	Test t1,t2;
	t1.s = "t1";
	t2.s = "t2";
	t2 = t1; // calls assignment operator, same as "t2.operator=(t1);"
	cout << "t1: " << t1.s << ",t2: " << t2.s << endl; 
	
	t1.s = "again_t1";
	t2.s = "again_t2";

	cout << "t1: " << t1.s << ",t2: " << t2.s << endl; 

	Test t3 = t1; // calls copy constructor, same as "Test t3(t1)"	
	
	return 0;
}
