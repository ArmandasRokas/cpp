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
    std:vector<int> products; 

    for(int i = 0; i < std::max(a.size(), b.size()); i++ ){
        int a_element;
        int b_element; 
        
        if(i < a.size()){
            // cout << a[i] << ' ';
            a_element = a[i];
        } else{
            a_element = 0;
        }
    
        if(i < b.size()){
            // cout << a[i] << ' ';
            b_element = b[i];
        } else{
            b_element = 0;
        }
                // products.push_back(1);

        products.push_back((a_element*b_element)); 
    }
    
    int finalRes = 0;
    for(int e: products){
        finalRes += e;
    }
    
    cout << finalRes;
 //   printVector(a);
 //   printVector(b);

    return 0;
}


void printVector(std::vector<int> & v){
    for(auto e: v){
        cout << e << ' ';
    }
}

