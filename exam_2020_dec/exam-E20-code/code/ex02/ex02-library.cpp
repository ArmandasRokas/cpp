#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if(list == nullptr){
        return 0;
    } else {
        return list->times + length(list->next); 
    }
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {

    if(list == nullptr){
        Elem * first = new Elem();
        first->next = nullptr;
        first->times = 1;
        first->value = v;
        return first;
    }

    Elem * curr = list;
    while(curr != nullptr){
        if(curr->value == v){
            curr->times++;
            return list;
        } 
        curr = curr->next;
    }
    
    curr = list;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    Elem * e = new Elem();
    e->next = nullptr;
    e->times = 1;
    e->value = v;
    curr->next = e;

    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    Elem * first = new Elem();
    first->next = nullptr;
    first->times = 1;
    first->value = data[0];
    
    for(int i=1; i<n; i++){
        append(first, data[i]);
    }
    return first;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
