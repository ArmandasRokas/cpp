#include "doubly-linked.h"

namespace double_linked_list_helper
{
    Node * last(Node * first){ // implemented as static member, because I can not change class structure for this exercise. 
        Node * curr = first;
        while(curr->next != NULL){
            curr = curr->next; 
        }
        return curr;
    }
}

List::List(void){
    this->first = NULL;
}

List::~List(){
    // if(this->first == NULL){
    //     return;
    // }
    Node * curr = this->first;
    Node * next;
    while(curr != NULL){
        next = curr->next;
        delete curr;
        curr = next;
    }
}

void List::insert(int n){
    Node * node = new Node; // had to use "new" keyword in order to alloce memory dynamically. If not, so the Node is removed from the memory after the method executed, which cause random val later in the execution. 
    node->val = n;
    node->next = NULL;
    if(this->first == NULL){
        node->prev = NULL;
        this->first = node; 
    } else {
        Node * last_node = double_linked_list_helper::last(this->first); 
        node->prev = last_node;
        last_node->next = node;
    }

}

void List::reverse(){
    // Empty
    if(this->first == NULL){
        return;
    }
    // One element
//    if(this->first->next == NULL){
//        return;
//    }
    // Two elements
    
  //  this->first->next = NULL;
    Node * curr = this->first;
    Node * next = curr->next;
    curr->next = NULL;
    while(next != NULL){
        Node * two_times_next = next->next;
        next->next = curr;
        this->first = next;
        curr = next;
        next = two_times_next;
    }
    
    

}

void List::print(){
        string out;
    Node * curr;
    curr = this->first;
    while(curr != NULL){
        out += to_string(curr->val) + " ";
        curr = curr->next; 
    }
    cout << out.substr(0,out.length()-1); 
    cout << endl;
}

string List::toString(){
    string out;
    Node * curr;
    curr = this->first;
    while(curr != NULL){
        out += to_string(curr->val) + " ";
        curr = curr->next; 
    }
    return out.substr(0,out.length()-1); // remove last space
}






