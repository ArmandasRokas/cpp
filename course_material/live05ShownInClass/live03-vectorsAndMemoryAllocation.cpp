//============================================================================
// Name        : live03-vectorsAndMemoryAllocation.cpp
// Description : Containers & memory allocation.
//               Containers, e.g. vectors, should always be passed by reference
//============================================================================

#include<vector>
#include <iostream>

using namespace std;

vector<int> createVector() {
	vector<int> v(10);
	return v;
}

void badIdea(vector<int> v) {
	v.push_back(42);
}

void goodIdea(vector<int> &v) {
	v.push_back(42);
}

int main()
{
	vector<int> v = createVector();

	v.push_back(1);
	v.push_back(2);

	cout << "Vector contents: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;

	badIdea(v);
	cout << "Vector after badIdea(): ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;

	goodIdea(v);
	cout << "Vector after goodIdea(): ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;

	return 0;
}
