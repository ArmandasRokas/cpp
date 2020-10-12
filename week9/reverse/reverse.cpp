#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

void reverse(vector<int> &a, int n , int i); // pass vector by reference

int main(){
    string buf = "";
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

    reverse(nums, nums.size(), 0);

    for(int n: nums){
        cout << n << " "; 
    }
    cout << std::endl;

}

void reverse(vector<int> &a, int n , int i){

    int temp_left = a[i];
    a[i] = a[n-1-i];
    a[n-1-i] = temp_left;
    i++;
    if(i > n-1-i){
        return;  // maybe possible to return reversed array 
    } else {
        return reverse(a, n, i);
    }
}

/**
// https://stackoverflow.com/questions/49930296/recursively-reverse-an-array
//Recursive function for Reversing array
void reverse_arr(int a[],int size){
    if(size <= 1 ){
        return ;
    }
    else{
        int temp;
        int i= 0;
        temp = a[i];
        a[i]= a[size-1];
        a[size -1] = temp;
        reverse_arr(&a[1], size-2); // moves a pointer 
    }
}

**/