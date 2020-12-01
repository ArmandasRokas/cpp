#include "ex04-library.h"
#include <iostream>

using namespace std;

//Do not modify
template<class T>
void Node<T>::printNode(){
	cout << "Name: " << name << ", value: " << value ;
	cout << ", children: " << children.size() << endl;
}

//Exercise 4 (a) Check and correct if necessary
template<class T>
Node<T>::Node(string name, T value): name(name), value(value) {}

//Exercise 4 (b) Implement getName, getValue, and addChild
template<class T>
string Node<T>::getName(){
	return this->name;
}

template<class T>
T Node<T>::getValue(){
	return this->value;
}

template<class T>
void Node<T>::addChild(Node<T> * child){
	this->children.push_back(child);
}

//Exercise 4 (c) Implement this method
template<class T>
void Node<T>::printLeafNodes(){
	if(this->children.empty()){
		cout << this->name << " " << this->value << " ";
	} else {
		for(Node<T> * child: this->children){
			child->printLeafNodes();
		}
	}
}

//Exercise 4 (d) Implement this method
template<class T>
int Node<T>::countMembersOfSubTree(){
	if(this->children.empty()){
		return 1;
	} else {
		int res=0;
		for(Node<T> * child: this->children){
			res += child->countMembersOfSubTree();
		}
		return 1 + res; 
	}
}

//Do not modify
template class Node<string>;