#include "ex03-library.h"
#include <iostream>

//Do not modify
WordsList::WordsList(){
	allWords.push_back("121");
	wordsToPalindromeDistance["121"]=0;
	allWords.push_back("122");
	wordsToPalindromeDistance["122"]=1;
}

//Exercise 3 (a) implement this method
void WordsList::print(){
	cout << allWords.size() << " words:";
	for(auto word: this->allWords){
		cout << " " << word << " (" << wordsToPalindromeDistance[word] <<")";
	}
	cout << endl;
}

//Exercise 3 (b) implement this method
int WordsList::distancePalindrome(string s){
	int distance=0;
	for(int i=0; i<s.length()/2; i++){
		if(s[i] != s[s.length()-1-i]){
			distance++;
		}
	}
	return distance;
}

//Exercise 3 (c) implement this method
void WordsList::addWord(string word){

	allWords.push_back(word);
	wordsToPalindromeDistance[word] = this->distancePalindrome(word);
}

//Exercise 3 (d) implement this method
int WordsList::palindromeWords(){
	int res = 0;
	for(auto word: allWords){
		if(wordsToPalindromeDistance[word]==0){
			res++;
		}
	}
	return res;
}