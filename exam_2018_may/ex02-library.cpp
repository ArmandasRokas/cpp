#include "ex02-library.h"
#include <iostream>

//Do not modify
void printSet(set<string> s){
  if(s.size()==0){
    cout << " No nodes\n";
  }
  else{
    set<string>::iterator it;
    for (it=s.begin(); it!=s.end(); ++it){
      cout << ' ' << *it << "\n";
    }
  }
  cout << "\n";
}

//Exercise 2 (a) Check and correct if necessary
void computeLeaves(Node *n, set<string> & leaves){
  if(n->left == nullptr && n->right == nullptr){
    leaves.insert(n->name);
    return;
  } 
  if(n->left != nullptr){
    computeLeaves(n->left,leaves);
  } 

  if(n->right != nullptr){
    computeLeaves(n->right,leaves);
  }
}

//Exercise 2 (b) Implement this function
int countNodes(Node * n) {
 if(n->left == nullptr && n->right == nullptr){
    return 1;
  } 
  int res = 0;
  if(n->right != nullptr){
    res += countNodes(n->right);
  }
  if(n->left != nullptr){
    res += countNodes(n->left);
  }
  return 1 + res;
}

int countDescendants(Node * n){
    int num_nodes = countNodes(n);
    return num_nodes-1; 
}


