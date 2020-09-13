#include <iostream> 
#include<vector>                
#include<string>
#include<sstream>
#include<iostream>
#include <bits/stdc++.h> 
#include <algorithm>    // std::max
                    
using std::cin; 
using std::cout;                 
using std::vector;
using std::string;


void printVector(std::vector<int> & v);

int main () // This the main entry of the program
{
    std::vector<int> a;
    std::vector<int> b;

    string buf;
    getline(cin, buf);
    std::istringstream ssin(buf);
    
    char input;
    while(ssin >> input){
        if(input == 'a'){
            int num;
            ssin >> num;
            a.push_back(num);
        } else if (input == 'b'){
            int num;
            ssin >> num;
            b.push_back(num);
        }
    }

  //  sort(a.begin(), a.end());
  //  sort(b.begin(), b.end());

    for(int i = 0; i < std::max(a.size(), b.size()); i++ ){
        if(i < a.size()){
            cout << a[i] << ' ';
        }
        if(i < b.size()){
            cout << b[i] << ' ';
        }
    }
    

 //   printVector(a);
 //   printVector(b);

    return 0;
}


void printVector(std::vector<int> & v){
    for(auto e: v){
        cout << e << ' ';
    }
}

