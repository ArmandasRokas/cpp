#include <iostream>

using namespace std;

class Test{
	private:
		int& num;
	public:
		Test(int& num): num(num){};
		int getNum(){return num;};
};

int main(){
	int num = 30;
	Test t(num);
	cout << t.getNum() << endl;
	num = 99;
	cout << t.getNum() << endl;
}
