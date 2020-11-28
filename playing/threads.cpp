/*
 *g++ threads.cpp -o threads.out -lpthread
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;


int ** createMatrix(unsigned int n, unsigned int m){
  int ** A = new int *[n];
  for(unsigned int i = 0; i<n; i++){
    A[i] = new int[m];
  }
  return A;
}

void initMatrix(int ** A, unsigned int n, unsigned int m){
  	for(int i=0;i<n;i++){
		  for(int j=0;j<m;j++){
			  A[i][j]=0;
		}
	}        
}


void count(int n){
	for(int i=0; i<n; i++){
		cout << i << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void deallocateMatrix(int ** A, unsigned int n){
    for(int i = 0; i<n;i++){
      delete[] A[i];
    }
    delete[] A;       
}

void matrix_creation_loop(int n){
	for(int i=0;i<n;i++){
		int n = 100;
		int m = 100;
		int ** A= createMatrix(n,m);
		initMatrix(A,n,m);
		deallocateMatrix(A,n);
	}
}



int main(){
	vector<thread> threads;
	for(int i = 0;i<10;i++){
		threads.push_back(thread(matrix_creation_loop, 1000000));
	}
	
	for(thread& t: threads){
		t.join();
	}
	
	//matrix_creation_loop(1000000);
	//thread t(count,10);
	//thread t2(count,10);
	//t.join();
	//t2.join();
	//count(10);
	return 0;
}
