#include <iostream>
using namespace std;

class Test{
	private:
		int a,b,c;
	public:
		Test(int a, int b, int c){
			this->a=a;
			this->b=b;
			this->c=c;
		}

		void print(){
			cout << "a: " << this->a << ", b: " << this->b << ", c: " << this->c <<endl ; 
		}
		// Overriding default assignment operator, but there is no need, because the similar would be created by default. It is just an example. 
		Test& operator=(const Test & t){
			cout << "Test assignment operator called" << endl;
			this->a = t.a;
			this->b = t.b;
			this->c = t.c;
			return *this;
		}
};

class Test_B{
	private:
	       Test t;
       	public:
				// Initialization list	
		Test_B(Test t): t(t){}
//	       Test_B(Test& t): t(t){ BAD performance: 6) https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/  
//			this->t = t;
//		}
		void print(){
			t.print();
	 	}		
};

int main(){
	Test t1(1,2,3);
	Test t2(0,0,0);
//	t2 = t1;
//	t2.print();
	Test_B tb1(t1);
	Test_B tb2(t2);
	//for(unsigned int i=0; i< 100000000000; i++){
	tb2=tb1;
	//}
	tb2.print();

	return 1;
}
