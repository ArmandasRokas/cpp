#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

// Exercise 2
vector<string> match(vector<string> & u,
                     vector<string> & v){
    
    if(u.size() == 0 || v.size()==0 ){
        return vector<string>();
    }
    // Remove first elements
    std::vector<string> t_u(u.begin()+1, u.end());  
    std::vector<string> t_v(v.begin()+1, v.end());
    
    if(u[0] == v[0]){

        std::vector<string> from_match =  match(t_u,t_v);
        std::vector<string> res;
        res.push_back(u[0]);
        res.insert(res.end(), from_match.begin(), from_match.end());
        return res;
    }

    if(match(u,t_v).size() >= match(t_u,v).size()){
        return match(u,t_v);
    } else {
        return match(t_u,v);
    }

    
}

// Do not modify
vector<string> read_until(string stop){
    vector<string> u;
    string e;
    while(true){
        cin >> e;
        if(cin.fail() || e == stop) break;
        u.push_back(e);
    }
    return u;
}

// Do not modify
void display(vector<string> & u){
    for(unsigned int i=0; i<u.size(); i++)
        cout << u[i] << " " ;
    cout << endl;
}
