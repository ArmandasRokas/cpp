#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int attack(int &Z, priority_queue<int> &A, int num_attacks);

int main() {
	int T,N,Z;
	priority_queue<int> A;
	cin >> T;
	
	
	cin >> N;
	cin >> Z;
	for(int i=0; i<N; i++){
		int Ai;
		cin >> Ai;
		A.push(Ai);
	}

//	cout << T << " " << N << " " << Z << endl; 
//	while(!A.empty()){
//		cout << A.top() << " ";
//		A.pop();
//	}	

	cout << endl;
	int num_attacks = attack(Z,A,0);
	if(num_attacks<0){
		cout << "Evacuate " << endl;
	} else{
		cout << num_attacks << " "  << endl;
	}


	cout << endl;
	return 0;
}

int attack(int &Z, priority_queue<int> &A, int num_attacks){
	if(Z>0){
		int curr_soldier = A.top();
		if(curr_soldier <= 0){
			return -1;
		}
		A.pop();
		Z = Z-curr_soldier;
		curr_soldier = curr_soldier/2;
		A.push(curr_soldier);
		return attack(Z, A, ++num_attacks);
	} else{
		return num_attacks;
	}
}



