#ifndef __fibonacci_tree__
#define __fibonacci_tree__

#include <vector>

struct Node {
    int val;        // contains the value
    Node * left = NULL;    // pointer to the next element in the list
    Node * right = NULL;    // pointer to the previous element in the list
};

class FibonacciTree{
    public:
        FibonacciTree(int n); // Constructor
        std::vector<int> get_values(void);
        int get_size(void);
        int get_depth(void);
        int get_leafs(void);
    private:
        Node * root;    
};

#endif