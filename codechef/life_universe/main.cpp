#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> res;
	int input;
	cin >> input;
	while(input != 42){
	    res.push_back(input);
	    cin >> input;
	}
	
	vector<int>::iterator i;
	for(i=res.begin(); i != res.end(); i++){
	    cout << *i << endl;
	}
	return 0;
}

