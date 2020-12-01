#include <iostream>

using namespace std;

static const int SIZE = 100000;

int main(){
	
	int * arr= new int[SIZE]{};
	for(int i=0; i < SIZE ; i++){
		if(arr[i] != 0){
			cerr << "Initialization failed" << endl;
		}
	}
}
