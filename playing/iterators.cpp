#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void){
	
	// Declaring a vector
	vector<int> v = {1,2,3};
	
	// Declaring an iterator
	vector<int>::iterator i;

	// Accessing the elements using iterators
	for(i = v.begin(); i!=v.end(); i++ ){
		cout << *i << " ";
	}
	cout << endl;
}
