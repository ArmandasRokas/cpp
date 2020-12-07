#include "ex02-library.h"
#include <iostream>

//Exercise 2 (a) Implement this function
string reverse(string s, int n){
	int index_swap_with = (s.length()-1)-n;
	if(n<=index_swap_with){
		return s;
	} else {
		swap(s[n], s[index_swap_with]);
		return reverse(s, --n);
	}
}

//Exercise 2 (b) Implement this function
bool isPalindrome(string s, int n1, int n2){
	if(n2<=n1){
		return true;
	} else {
		if(s[n1] != s[n2]){
			return false;
		} else{
			return isPalindrome(s, ++n1, --n2);
		}
	}
}

//Exercise 2 (c) Implement this function
int distancePalindrome(string s, int n1, int n2){
	if(n2<=n1){
		return 0;
	} else{
		if(s[n1] != s[n2]){
			return 1 + distancePalindrome(s, ++n1, --n2);
		} else{
			return distancePalindrome(s, ++n1, --n2);
		}
	}
}