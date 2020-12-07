#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

const int n = 1000000;

class Test{	
	private:
		vector<int> ints;
	public:
		Test(){
			ints.push_back(1);
			ints.push_back(1);
			ints.push_back(1);
			ints.push_back(1);
		}
};

class A{
	private:
		Test t;
	public:
		A(Test);
};
A::A(Test t){
	this->t = t;
};


class B{
	private:
		Test t;
	public:
		B(Test);
};
B::B(Test t): t(t){};

int main(){
	Test t;

	chrono::time_point<chrono::system_clock> start_time;
	chrono::time_point<chrono::system_clock> end_time;

	start_time = chrono::system_clock::now();
	for(unsigned int i=0; i<n; i++){
		A a(t);
	}
	end_time = chrono::system_clock::now();
	double a_duration = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();

	start_time = chrono::system_clock::now();
	for(unsigned int i=0; i<n; i++){
		B b(t);
	}
	end_time = chrono::system_clock::now();
	double b_duration = chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count();

	cout << "A: " << a_duration << "B: " << b_duration << endl;
}
