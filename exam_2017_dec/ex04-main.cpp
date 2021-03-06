//============================================================================
// Name        : ex04.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Exercise 4 - Parametric Double-ended Queue
//============================================================================

#include <iostream>
#include "ex04-library.h"

using namespace std;

void createDeque(){
	mydeque<int> deque;


	for(int i=0; i<100000000;i++){
		for(int i=0; i<10;i++){
			deque.push_back(2);
			deque.push_back(1);
			deque.push_back(3);
		}

		while(deque.getSize()>0){
			deque.pop_front();
		}
	}
}

int main() {
	//for(int i=0; i<1000000;i++){
		createDeque();
	//}

	mydeque<int> deque;

	deque.push_front(2);
	deque.push_front(1);
	deque.push_back(3);

	deque.print();

	cout <<"\n";
	cout << "The first element is: ";
	deque.print_front();
	cout << "The last element is: ";
	deque.print_back();

	do{
		cout <<"\n";
		cout << "pop_front(): ";
		cout <<deque.pop_front() <<"\n";
		deque.print();
	}while(deque.getSize()>0);

	cout <<"\n";
	cout << "pop_front(): ";
	cout << deque.pop_front() <<"\n";

	return 0;
}

