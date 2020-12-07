#include <iostream>
#include <vector>

using namespace std;

class Parent{
	public:
	virtual void print(){
		cout << "Parent: print" << endl;
	}
	void show(){
		cout << "Parent: show" << endl;
	}
};

class Child: public Parent{
	public:
	void print(){
		cout << "Child: print" << endl;
	}
	void show(){
		cout << "Child: show" << endl;
	}

};

int main(){
	// Using pointers
	Parent *p_ptr;
	Child c;
	p_ptr = &c;
	
	p_ptr->print();
	p_ptr->show();

	// References
	Child c1;
	Parent& p1 = c1;
	p1.print();
	p1.show();

	// Vectors
	Child c10;
	Child c11;
	Child c12;
	vector<Parent *> childs; // It is not possible to use references
	childs.push_back(&c10);
	childs.push_back(&c11);
	childs.push_back(&c12);

	for(auto a: childs){
		a->print();
		a->show();
	}
}
