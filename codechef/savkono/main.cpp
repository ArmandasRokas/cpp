#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int attack(int &Z, priority_queue<int> &A, int num_attacks);

int main() {
	int T;
	vector<int>Zs; //Ns,
	vector<priority_queue<int>> As;
	cin >> T;
	
	for(int i=0; i<T; i++){
		int N,Z;
		cin >> N;
		cin >> Z;
		priority_queue<int> A;
		for(int i=0; i<N; i++){
			int Ai;
			cin >> Ai;
			A.push(Ai);
		}
	//	Ns.push_back(N);
		Zs.push_back(Z);
		As.push_back(A);
	}

	for(int i=0; i<T; i++){
		int num_attacks = attack(Zs[i],As[i],0);
		if(num_attacks<0){
			cout << "Evacuate " << endl;
		} else{
			cout << num_attacks << " "  << endl;
		}
	}



//	cout << T << " " << N << " " << Z << endl; 
//	while(!A.empty()){
//		cout << A.top() << " ";
//		A.pop();
//	}	

	cout << endl;


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



