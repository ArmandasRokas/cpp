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

vector::vector(){
    this->first = nullptr;
    this->vsize = 0;
}

unsigned int vector::size(){
    return this->vsize;
}

void vector::push_back(int i){
    push_backR(i, &(this->first));
}

void vector::push_backR(int x, Node<int> **p){
    if(*p == nullptr){
        Node<int>* node = new Node<int>;
        node->content = x;
        node->next = nullptr;
        *p = node;
        this->vsize++;
    } else{
        push_backR(x, &((*p)->next));
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
