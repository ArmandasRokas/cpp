#include <iostream>
using namespace std;

class Complex{
	private:
		int real, imag;
	public:
		Complex(int r=0,int i=0){
			this->real = r;
			this->imag = i;
		}

		Complex operator+(Complex const &c){
			Complex res;
			res.real = this->real + c.real;
			res.imag = this->imag + c.imag;
			return res;
		}
		void print(){
			cout << real << " +i" << imag << endl;
		}
};

int main(){
		Complex c1(1,2);
		Complex c2(2,3);
		Complex c3 = c1+c2;
		c3.print();
		return 1;
}
