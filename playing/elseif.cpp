#include <iostream>

using namespace std;

int main(){
	int i = 10;

	if(i < 100){
		cout << "i<100" << endl;
	} else if(i<200){
		cout << "i<200" << endl; // not executed
	}
}
