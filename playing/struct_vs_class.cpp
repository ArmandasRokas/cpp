#include <iostream>

using namespace std;

class Test_class{
	public: 
		int i;
};


struct Test_struct{
	int i;
	void print(){cout<< "print() in struct is invoked"<<endl;};
};

struct Test_struct_child: Test_struct{};



int main(){
	Test_class t_class;
	t_class.i = 1;

	Test_struct t_struct;
	t_struct.i = 2;

	Test_struct_child t_struct_child;
	t_struct_child.i = 3;

	cout << "t_class: " << t_class.i << endl;
	cout << "t_struct: " << t_struct.i << endl;
	cout << "t_struct_child: " << t_struct_child.i << endl; 
	
	t_struct.print();
}
