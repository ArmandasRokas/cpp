#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Test{
	public:
		string value;
};

Test create_Test_return_value(void){
	Test t;
	t.value = "test from value";
	return t;
}


// WRONG gives warning: reference to local variable ‘t’ returned and segmantation error
// You can't return a reference to a local variable. It will get destroyed as soon as the function exits.
Test & creates_Test_return_reference(void){
	Test t;
	t.value = "test from reference";
	return t;
}	

int main(void){

	Test v_t = create_Test_return_value();
	cout <<  v_t.value << endl;	
	
	// Segmentation error
	 Test  r_t = creates_Test_return_reference();
	cout << r_t.value << endl;	

	

}
