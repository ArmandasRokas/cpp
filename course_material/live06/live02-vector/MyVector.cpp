#include "MyVector.h"

#include <iostream>

// The constructor
MyVector::MyVector(void) {
    // We decide here to start with a small capacity
    capacity = 1;
    vsize = 0;
    // We allocate the space we need dynamically
    content = new int[capacity];
    return;
}

// The constructor
MyVector::MyVector(int initialCapacity) {
    // We decide here to start with a small capacity
    capacity = initialCapacity;
    vsize = 0;
    // We allocate the space we need dynamically
    content = new int[capacity];
    return;
}

// Destructor method
MyVector::~MyVector(void) {
    // We need to deallocate the array
    delete [] content;
    return;
}

void MyVector::resize() {
    // Save pointer to current array
    int *old_content = content;

    // Allocate new array: we try to double the current capacity
    capacity = capacity * 2;
    content = new int[capacity];

    // Copy content
    for (unsigned int i = 0; i < vsize; i++) {
        content[i] = old_content[i];
    }

    // Delete old array
    delete [] old_content;
}

unsigned int MyVector::size(void) {
    return vsize;
}

void MyVector::push_back(int x) {

    // Resize array if full
    if (vsize == capacity) {
        resize();
    }

    // Insert new element
    content[vsize] = x;
    vsize = vsize + 1;

}

int MyVector::at(unsigned int i) {
    // If we are accessing outside the last element, we raise an error
    if (i >= vsize){
        throw std::out_of_range("Access out of range");
    }
    return content[i];
}

// Here we overload the operator [_] to access MyVector elements in array-style
int & MyVector::operator[](unsigned int i)
{
    if (i>=vsize) {
        throw std::out_of_range("Access out of range");
    }
    // Note that we do not return an element but a reference to an element (see return type)
    return content[i];
}

// Our custom assignment operator, needed to handle dynamic allocations
MyVector & MyVector::operator=(MyVector &v) {
    // The next 3 lines show what the default assignment operator = would do
    this->capacity = v.capacity;
    this->vsize = v.vsize;
    // this->content = v.content; // Would be wrong: would just copy the pointer

    // Instead of copying a pointer, we want to deallocate our old contents...
    delete[] this->content;
    // ...allocate an array matching our capacity (which is also v's capacity)...
    this->content = new int[this->capacity];
    // ...and copy the contents of v
    for (unsigned int i=0; i < vsize; i++) {
        this->content[i] = v.content[i];
    }
    return * this;
}

