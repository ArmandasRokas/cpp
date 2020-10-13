#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

bool isPalindrome(int * nums, int size);

int main(){
    string buf;
    getline(cin, buf);
    if(buf == ""){
        return 0;
    }
    std::istringstream ssin(buf);

    // declare input
    vector<int> nums;
    int input;

    while(ssin >> input){
        nums.push_back(input);
    }
    
    bool b = isPalindrome(&nums[0], nums.size());

    if(b==0){
        cout << "no" << endl;
    } else {
        cout << "yes" << endl; 
    }
}

bool isPalindrome(int * nums, int size){
    if(size<2)
        return 1;
    if(nums[0] != nums[size-1])
        return 0;
    return isPalindrome(&nums[1], size-2);
}