#include "fibonacci_tree.h"
#include <vector>
#include <iostream>

namespace fibonacci_tree_helper
{
    void traverse(std::vector<int> &values, Node* node){
        values.push_back(node->val);
        if(node->left != NULL){
            traverse(values, node->left);
        }
        if(node->right != NULL){
            traverse(values, node->right);
        }
    }

    Node * build_fabinacci_tree(int n){
        if(n<= 1){
            Node * node = new Node;
            node->val = 1;
            return node; 
        }
        Node* curr = new Node;
        curr->left = fibonacci_tree_helper::build_fabinacci_tree(n-1);
        curr->right = fibonacci_tree_helper::build_fabinacci_tree(n-2);
        curr->val = curr->left->val + curr->right->val;
        return curr;
    }

    int get_depth(Node * node){
        if(node->left == NULL){
            return 1;
        } 
        if(node->right == NULL){
            return 1;
        }
        int left_branch_depth = get_depth(node->left);
        int right_branch_depth = get_depth(node->right);
        return left_branch_depth >  right_branch_depth ? left_branch_depth+1 : right_branch_depth+1;
    }

     int get_size(Node * node){
        if(node->left == NULL){
            return 1;
        } 
        if(node->right == NULL){
            return 1;
        }
        int left_branch_size = get_size(node->left);
        int right_branch_size = get_size(node->right);
        return left_branch_size + right_branch_size + 1;
    }

    int get_leafs(Node * node){
        if(node->left == NULL){
            return 1;
        } 
        if(node->right == NULL){
            return 1;
        }
        int left_branch_size = get_leafs(node->left);
        int right_branch_size = get_leafs(node->right);
        return left_branch_size + right_branch_size;
    }
}

FibonacciTree::FibonacciTree(int n){
    this->root  = fibonacci_tree_helper::build_fabinacci_tree(n);
}

std::vector<int> FibonacciTree::get_values(){
    std::vector<int> res;
    fibonacci_tree_helper::traverse(res, this->root);
    return res;
}

int FibonacciTree::get_size(){
    return fibonacci_tree_helper::get_size(this->root);
}

int FibonacciTree::get_depth(){
    return fibonacci_tree_helper::get_depth(this->root);
}
int FibonacciTree::get_leafs(){
    return fibonacci_tree_helper::get_leafs(this->root);
}

