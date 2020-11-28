#include <iostream>

using namespace std;

class A{
	private:
	       	int num;
	public: 
		A(){num=123;}
		friend class B;
};

class B{
	public:
		void showA(A& a){
			cout << a.num << endl;
		}
};

int main(){
	A a;
	B b;
	b.showA(a);
}

