//============================================================================
// Name        : live02-vectors.cpp
// Description : Motivation for using templates: vector of int, of double, ...
//               all share most of the code.
//============================================================================

#include <iostream>
using namespace std;

#include "MyVectorOfInt.h"
#include "MyVectorOfDouble.h"
#include "MyVectorWithTemplates.h"

// See differences between .h and .cpp files using https://www.diffnow.com/

void experimentInt();
void experimentDouble();
void experimentTemplate();

int main() {
	experimentInt();
	//experimentDouble();
	//experimentTemplate();

	return 0;
}

void experimentInt() {
	cout << "*** Using MyVectorOfInt" << endl;

	MyVectorOfInt a;
	MyVectorOfInt b(10);

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < a.getSize(); i++) {
		// cout << a.at(i) << " ";
		cout << a[i] << " ";
	}
	cout << endl;
	// Output: 0 1 2 3 4 5 6 7 8 9

	for (int i = 0; i < a.getSize(); i++) {
		a[i] = a[i] + 2;
	}
	cout << endl;

	for(int i = 0; i < a.getSize(); i++){
		cout << a[i] << " ";
	}
	// Output: 2 3 4 5 6 7 8 9 10 11
}



void experimentDouble() {
	cout << "*** Using MyVectorOfDouble" << endl;

	MyVectorOfDouble a;
	MyVectorOfDouble b(10);

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < a.getSize(); i++) {
		// cout << a.at(i) << " ";
		cout << a[i] << " ";
	}
	cout << endl;
	// Output: 0 1 2 3 4 5 6 7 8 9

	for (int i = 0; i < a.getSize(); i++) {
		a[i] = a[i] + 2;
	}
	cout << endl;

	for(int i = 0; i < a.getSize(); i++){
		cout << a[i] << " ";
	}
	// Output: 2 3 4 5 6 7 8 9 10 11
}



void experimentTemplate(){
	cout << "*** Using MyVectorWithTemplates" << endl;

	MyVectorWithTemplates<int> a;
	MyVectorWithTemplates<int> b(10);
	//MyVectorWithTemplates<double> a;
	//MyVectorWithTemplates<double> b(10);

	for (int i = 0; i < 10; i++) {
		a.push_back(i);
	}

	for (int i = 0; i < a.getSize(); i++) {
		// cout << a.at(i) << " ";
		cout << a[i] << " ";
	}
	cout << endl;
	// Output: 0 1 2 3 4 5 6 7 8 9

	for (int i = 0; i < a.getSize(); i++) {
		a[i] = a[i] + 2;
	}
	cout << endl;

	for(int i = 0; i < a.getSize(); i++){
		cout << a[i] << " ";
	}
	// Output: 2 3 4 5 6 7 8 9 10 11
}

