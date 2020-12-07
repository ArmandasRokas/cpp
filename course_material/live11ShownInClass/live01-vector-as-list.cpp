#include <iostream>
#include "linked-list.h"

using namespace std;

class vector {
public:
    // Constructor method
    vector(void);
    // Destructor method
    ~vector(void);
    
    // Other useful methods
    unsigned int size(void);
    void push_back(int);
    int at(unsigned int);
    int & operator[](unsigned int);
    
    // User-defined assignment
    vector & operator=(vector &);
    
private:
    // Private members
    // used to implement the class, not meant for the user
    // the vector is implemented as a linked list
    Node<int> *first;
    // the size is kept updated for efficiency
    unsigned int vsize;
    
    // some internal methods
    void push_backR(int x, Node<int> **p);
    int& atRec(unsigned int i, Node<int> *curr);
    void erase(void);
    void eraseR(Node<int> *p);
};

// The constructor
vector::vector(void){
    this->first = nullptr;
    this->vsize = 0;
}

// Destructor method
vector::~vector(void){
    // We need to deallocate the list
    erase();
    return;
}

unsigned int vector::size(void) {
    return this->vsize;
}

// push_back implemented using recursion
// it can be also implemented with a loop

void vector::push_back(int x){
    push_backR(x, &(this->first));
}

void vector::push_backR(int x, Node<int> **pp) {
    if (*pp == nullptr) {
        Node<int> *newNode = new Node<int>;
        newNode->content = x;
        newNode->next = nullptr;
        (*pp) = newNode;
        this->vsize = this->vsize + 1;
    } else {
        push_backR(x, &((*pp)->next));
    }
}

int vector::at(unsigned int i) {
    // we check if we are accessing an element of the vector
    // otherwise we raise an error
    if (i >= vsize) {
        throw std::out_of_range("you went out of range of your vector!");
    }
    return atRec(i, this->first);
}

int& vector::atRec(unsigned int i, Node<int> *curr) {
    if (i == 0) {
        return curr->content;
    } else {
        return atRec(i-1, curr->next);
    }
}

// Here we overload the operator _[_] to access
// vector elements in array-style
int &vector::operator[](unsigned int i) {
    // we check if we are accessing an element of the vector
    // otherwise we raise an error
    if (i >= vsize) {
        throw std::out_of_range("you went out of range of your vector!");
    }
    return atRec(i, this->first);
}

// A user defined assignment operator
vector &vector::operator=(vector & v) {
    // delete the current list
    erase();

    // copy v
    for (unsigned int i = 0; i < v.size(); i++) {
        this->push_back(v[i]);
    }
    
    return *this;
}

// Erase a vector, recursively
void vector::erase(){
    eraseR(first);
    first = nullptr;
    vsize = 0;
}

void vector::eraseR(Node<int> *p) {
    if (p == nullptr) {
        return;
    } else {
        eraseR(p->next);
        cout << "*** Deleting node with element: " << p->content << endl;
        delete p;
    }
}

int main(void){
    // we declare a vector a
    vector a;
    
    // we insert some numbers with push_back
    for (unsigned int i = 0; i < 10; i++) {
        cout << "Adding element: " << i << endl;
        a.push_back(i);
        cout << "The size of the list is now: " << a.size() << endl;
        cout << "The value at position " << i << " is: " << a.at(i) << endl;
    }
    
    // we access and manipulate some elements in array-style
    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = a[i] * 10; // a[i-1] + a[i-2];
    }
    
    // we access some elements usint at()
    cout << "Vector after initialization: " << endl;
    for (unsigned int i = 0; i < a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;
    
    vector b;
    // we set b to be equal to a
    b = a;

    // we access and manipulate some elements in array-style
    for (unsigned int i = 0; i < a.size(); i++) {
        a[i] = a[i] * 100; // a[i-1] + a[i-2];
    }

    cout << "Copy of the vector: " << endl ;
    for (unsigned int i=0; i<b.size(); i++) {
        cout << b.at(i) << " ";
    }
    cout << endl;

    cout << "Current contents of vector a: " << endl ;
    for (unsigned int i=0; i<a.size(); i++) {
        cout << a.at(i) << " ";
    }
    cout << endl;

    return 0;
}
