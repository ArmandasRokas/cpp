#include <iostream>
#include <vector>

using namespace std;

class Test{
	private:
		vector<int> v;
};

int main(){
	// Does not leak
	for(unsigned int i=0; i<10000000000;i++){
		vector<Test *> tests;
		Test t1;
		Test t2;
		Test t3;
		tests.push_back(&t1);
		tests.push_back(&t2);
		tests.push_back(&t3);
	}

	return 1;
}
