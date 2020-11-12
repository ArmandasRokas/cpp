#include "test.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "fibonacci_tree.h"
#include "test.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

void given_fibonacci_to_print(){
    FibonacciTree f(3); 
    vector<int> expected{3, 2, 1, 1, 1};
    vector<int> actual = f.get_values();



    if(expected != actual){
        std::cerr << "Test failed.";
        std::cout << "Actual: " << "{";
        for(int i = 0; i < actual.size(); i++){
            std::cout << actual[i] << ", ";
        }
        std::cout << "}";

        std::cout << ". Expected: " << "{";
        for(int i = 0; i < expected.size(); i++){
            std::cout  << expected[i] << ", ";
        }
        std::cout << "}" << endl;
    }
}

void given_get_depth(){
    FibonacciTree f(3);
    int expected = 3;
    int actual = f.get_depth();
    if(expected != actual){
        std::cerr << "Test failed." << "Expected: " << expected << ". Actual: " << actual << ". " << endl; 
    }
}

void given_get_size(){
    FibonacciTree f(3);
    int expected = 5;
    int actual = f.get_size();
    if(expected != actual){
        std::cerr << "Test failed." << "Expected: " << expected << ". Actual: " << actual << ". " << endl; 
    }
}

void given_get_leafs(){
    FibonacciTree f(3);
    int expected = 3;
    int actual = f.get_leafs();
    if(expected != actual){
        std::cerr << "Test failed." << "Expected: " << expected << ". Actual: " << actual << ". " << endl; 
    }
}


void testDriver(){
   given_fibonacci_to_print();
   given_get_depth();
   given_get_size();
}
