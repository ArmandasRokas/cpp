#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods

LimitedBuffer::LimitedBuffer(unsigned int capacity, int def){
    this->capacity = capacity;
    this->def = def;
};

void LimitedBuffer::write(int v){
    if(this->occupancy() < capacity){
        values.push_back(v);
    }
};

unsigned int LimitedBuffer::occupancy(){
    return values.size();
}

int LimitedBuffer::read() {
    if(values.empty()){
        return this->def;
    } else {
        int res = values[0];
        values.erase(values.begin());
        return res;
    }
}


// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
