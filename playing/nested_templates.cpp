#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<vector<vector<int>>> a;
	vector<int> i;
	i.push_back(1);
	vector<vector<int>> b;
	b.push_back(i);
	a.push_back(b);
	cout << a[0][0][0] << endl;
}
