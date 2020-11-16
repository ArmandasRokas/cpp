#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    english2danish[u] = v;
    danish2english[u] = v;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(string lang, string u){
    return english2danish[u];
}

// Exercise 3(c)
void Dictionary::insert_synonym(string lang, string u,
                                     string v){
    // Put your code here
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(string lang, string u){
    // Put your code here
}

// Exercise 3(e)
set<string> Dictionary::translate(string lang, string u){
    // Put your code here
}

