// it calls recursive. As for exampel d("B", "B") is 
// showed one line below. But when return a number?
// maybe when |u| or |v| is 0. So then use another sequance length

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> 

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int d(string a, string b);

int main(){
    string buf;
    getline(cin, buf);
    if(buf == ""){
        return 0;
    }
    std::istringstream ssin(buf);

    string a;
    string b;
    ssin >> a;
    ssin >> b;
    cout << d(a,b) << endl;
}
bool comp(int a, int b) 
{ 
    return (a < b); 
} 

int d(string a, string b){
    if(a.length() == 0)
        return b.length();
    if(b.length() == 0)
        return a.length();
    return std::min({
                        d(a.substr(1, a.length()), b.substr(0, b.length())) +1,
                        d(a.substr(0, a.length()), b.substr(1, b.length())) +1,
                        d(a.substr(1, a.length()), b.substr(1, b.length())) + ((a.substr(0,1) == b.substr(0,1))? 0 : 1)   
                    }, comp);
}