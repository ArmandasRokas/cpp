#include <iostream>

using namespace std;


namespace A{
	class B{
		public:
			static void print(){cout<<"Hi from class B of A "<< endl;}
	};
}

namespace C{
	class B{
		public:
			static void print(){cout<<"Hi from class B of C" << endl;}
		class D{
			public:
				static void print(){cout << "Hi from class D" << endl;}
		};	
	};
}

int main(){
	A::B::print();
	C::B::print();
	C::B::D::print();
	return 1;
}
