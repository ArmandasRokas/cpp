#include "test.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "doubly-linked.h"
#include "test.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

void reverse_list(){
    // Arrange
    List l;
    l.insert(2);
    l.insert(3);
    l.insert(4);

    // Act
    l.reverse();

    // Assert
    string expected = "4 3 2";
    string actual = l.toString();
    if(actual.compare(expected) != 0)
        cerr << "Test failed. Acual: " + actual + ". Expected: " + expected << endl;
}

void given_insert_two_numbers_return_not_empty_list(){
    List l;
    l.insert(2);
    l.insert(3);
    l.insert(4);
    string actual = l.toString();
    string expected =  "2 3 4";

    if(actual.compare(expected) != 0)
        cerr << "Test failed. Acual: " + actual + ". Expected: " + expected << endl;
}

void given_insert_return_not_empty_list(){
    List l;
    l.insert(2);
    string actual = l.toString();
    string expected =  "2";

    if(actual.compare(expected) != 0)
        cerr << "Test failed. Acual: " + actual + ". Expected: " + expected << endl;
}

void testDriver(){
    given_insert_return_not_empty_list();
    given_insert_two_numbers_return_not_empty_list();
    reverse_list();
}

