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
    danish2english[v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(string lang, string u){

    if(lang=="english"){
      //  map<string,string>::const_iterator it = english2danish.find(u);
      //  if(it==english2danish.end()){
        if(english2danish.find(u)==english2danish.end()){
            return "#unknown#";
        }
        return english2danish[u]; 
    } else if(lang=="danish"){
        //map<string,string>::const_iterator it = danish2english.find(u);
        if(danish2english.find(u)==danish2english.end()){
            return "#unknown#";
        }
        return danish2english[u];
    } else {
        return "#unknown#";
    }
}

// Exercise 3(c)
void Dictionary::insert_synonym(string lang, string u,
                                     string v){
    if(lang=="english"){
        english_synonyms[u].insert(v);
        english_synonyms[v].insert(u);
    } else if(lang=="danish"){
        danish_synonyms[u].insert(v);
        danish_synonyms[v].insert(u);
    }
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(string lang, string u){
    set<string> res;
    if(lang=="english"){
        res = english_synonyms[u];
    } else if(lang=="danish"){
        res = danish_synonyms[u];
    }
    return res;
}

// Exercise 3(e)
set<string> Dictionary::translate(string lang, string u){
    string lang_to;
    string translated;
    set<string> res;
    if(lang=="english"){
        translated = english2danish[u];
        lang_to = "danish";
    } else if(lang=="danish"){
        translated = danish2english[u];
        lang_to = "english";
    }
    res.insert(translated);
    set<string> synonyms = get_synonyms(lang_to,translated);
    res.insert(synonyms.begin(), synonyms.end());
    return res;
}

