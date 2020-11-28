#include <iostream>

using namespace std;

class Test{
	private:
		static int x;
	public:
		Test(){x++;};
		void increase_x(){x++;}
		int get_x(){return x;}
};

int Test::x = 0;

int main(){
	Test t1,t2,t3;
//	t.increase_x();
	cout << t1.get_x() << endl;
	cout << t2.get_x() << endl;
	cout << t3.get_x() << endl;
	
	return 1;
}
