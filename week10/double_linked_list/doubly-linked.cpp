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
    //delete node
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
    if(this->first == NULL){
        return;
    }
    Node * last = double_linked_list_helper::last(this->first);
    this->first = last;
    last->next = last->prev;
    last->prev = NULL; 
    
    
    Node * curr = last->next;

    while(curr != NULL){
        Node * original_prev = curr->prev;  
        curr->prev = curr->next;
        curr->next = original_prev;
        
        curr = curr->next;
    }

    /*this->first =last;
    last->next = last->prev;
    last->prev = NULL; 
    */

   /* Node * curr = last->next;

    Node * second_last = last->next;
    second_last->prev = second_last->next;
    second_last->next = NULL; 
*/

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






