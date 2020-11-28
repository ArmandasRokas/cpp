#include <algorithm>
#include <iostream>

#include "arithmetic-syntax-trees.h"

using namespace std;

// Constructor for leaf nodes (constants)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(unsigned int value) {
    this->type = Const;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// Constructor for internal nodes (left + right, or left * right)
ArithmeticSyntaxTree::ArithmeticSyntaxTree(NodeType type,
                                           ArithmeticSyntaxTree *left,
                                           ArithmeticSyntaxTree *right) {
    this->type = type;
    this->value = -999;
    this->left = left;
    this->right = right;
}

// Destructor
ArithmeticSyntaxTree::~ArithmeticSyntaxTree() {
    cout << "*** Destructor invoked for node: ";
    switch (this->type) {
    case Const:
        cout << this->value;
        break;
    case Add:
        cout << "+";
        break;
    case Mult:
        cout << "*";
        break;
    }
    cout << endl;

    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

int ArithmeticSyntaxTree::size(void) {
    switch (this->type) {
    case Const:
        return 1;
    case Add:
    case Mult:
        return 1 + this->left->size() + this->right->size();
    default:
        cout << "BUG! This should not happen!";
        return -1;
    }
}

int ArithmeticSyntaxTree::height(void) {
    switch (this->type) {
    case Const:
        return 1;
    case Add:
    case Mult:
        return 1 + max(this->left->height(), this->right->height());
    default:
        cout << "BUG! This should not happen!";
        return -1;
    }
}

// The number of leaves can be computed in a similar fashion to
// size() and height()
int ArithmeticSyntaxTree::leaves(void) {
    switch (this->type) {
    case Const:
        return 1;
    case Add:
    case Mult:
        return this->left->leaves() + this->right->leaves();
    default:
        cout << "BUG! This should not happen!";
        return -1;
    }
}

// Method that implements the pre-order traversal method
void ArithmeticSyntaxTree::traversePre(void) {
    // First, show the current node
    // Then, show descendants
    switch (this->type) {
    case Const:
        cout << this->value;
        return;
    case Add:
        cout << "+";
        break;
    case Mult:
        cout << "*";
        break;
    }
    cout << "(";
    this->left->traversePre();
    cout << ",";
    this->right->traversePre();
    cout << ")";
}

// Method that implements the in-order traversal method
void ArithmeticSyntaxTree::traverseIn(void) {
    // First, show the left descendant
    // Then, show the current node
    // Finally, show the right descendant
    switch (this->type) {
    case Const:
        cout << this->value;
        return;
    case Add:
        cout << "(";
        this->left->traverseIn();
        cout << ")";
        cout << "+";
        break;
    case Mult:
        cout << "(";
        this->left->traverseIn();
        cout << ")";
        cout << "*";
        break;
    }
    
    cout << "(";
    this->right->traverseIn();
    cout << ")";
}

int ArithmeticSyntaxTree::eval(){
       switch (this->type) {
    case Const:
        return this->value;
    case Add:
        return this->left->eval() + this->right->eval();
    case Mult:
        return this->left->eval() * this->right->eval();
    default:
        return -9999999;
    } 
}
