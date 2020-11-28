#include <iostream>
#include <vector>
#include <string>
#include "ex02-library.h"

using namespace std;

// Exercise 2
vector<string> match(vector<string> & u,
                     vector<string> & v){
    
    if(u.empty() || v.empty()){
        vector<string> empty_vector;
        return empty_vector;
    }

    string u_last_element = u[u.size()-1];
    string v_last_element = v[v.size()-1];

    if(u_last_element == v_last_element){
        vector<string> u2(u.begin(), u.end()-1);
        vector<string> v2(v.begin(), v.end()-1);
        vector<string> res;
        res = match(u2, v2);
        res.push_back(u_last_element);
        return res;
    }

    vector<string> p_v(v.begin(), v.end()-1);
    vector<string> p_u(u.begin(), u.end()-1);

  //  v.pop_back();
   // vector<string> p_v;
   // p_v = match(u, v);
   // v.push_back(v_last_element);

   // u.pop_back();
   // vector<string> p_u;
  //  p_u = match(u, v);

    if(match(u,p_v).size() >= match(p_u, v).size()){
        return match(u,p_v);
    } else {
        return match(p_u, v);
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
