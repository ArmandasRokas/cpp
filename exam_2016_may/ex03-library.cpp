#include <iostream>
#include <map>
#include <set>
#include <vector>
#include "ex03-library.h"

using namespace std;

// Exercise 3(a)
Dictionary::Dictionary(void){
    this->words.resize(2);
    this->synonyms.resize(2);
}

// Exercise 3(b)
// Check and correct if necessary
void Dictionary::insert_words(string u, string v){
    words[0][u] = v;
    words[1][v] = u;
}

// Exercise 3(b)
// Check and correct if necessary
string Dictionary::get_word(int lang, string u){
    if (lang < 0 || lang > 1) return "";
    return words[lang][u];
}

// Exercise 3(c)
void Dictionary::insert_synonym(int lang, string u,
                                     string v){
    if (lang < 0 || lang > 1) return;
    synonyms[lang][u].insert(v);
}

// Exercise 3(d)
set<string> Dictionary::get_synonyms(int lang, string u){
    set<string> A;
    if (lang < 0 || lang > 1) return A;
    return synonyms[lang][u];
}

// Exercise 3(e)
set<string> Dictionary::translate(int lang, string u){
    set<string> A;
    if (lang < 0 || lang > 1) return A;   
    int second_lang = lang ? 0 : 1;
    string translated = get_word(lang,u) ;
    set<string> res = get_synonyms(second_lang,translated );
    res.insert(translated);

    set<string> synonyms_to_translate = get_synonyms(lang, u);
    
    set<string>::iterator it;
    for(it = synonyms_to_translate.begin(); it !=synonyms_to_translate.end(); ++it){
        string translated_synonym = get_word(lang,*it);
        set<string> res_translated_synonym = get_synonyms(second_lang,translated_synonym );
        res.insert(res_translated_synonym.begin(),res_translated_synonym.end() );
        res.insert(translated_synonym);
    }

    
    return res;
}

