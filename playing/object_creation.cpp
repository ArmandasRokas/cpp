#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Point
{
	private:
		int x,y;
	public:
		Point(int x1, int y1){
			this->x = x1;
			this->y = y1;
		}

		Point(){
		}

		int getX(){
			return this->x;
		}
		int getY(){
			return this->y;
		}
		void setX(int x){
			this->x = x;
		}
		void setY(int y){
			this->y = y;
		}
};


int main(void){
	// Parameterized constructor
	Point p1(10,15);
	cout << p1.getX() << " " << p1.getY() << endl;	
	// Non-parameterized constructor
	Point p2;
	p2.setX(1);
	p2.setY(2);
	cout << p2.getX() << " " << p2.getY() << endl;	
	// Copy object
	Point p4 = p1;
	p1.setX(999); // does not change in p4
	p1.setY(999); // does not change in p4
	cout << p4.getX() << " " << p4.getY() << endl;	
	cout << p1.getX() << " " << p1.getY() << endl;
	// Reference object
	Point & p5 = p1;
	p1.setX(111);
	p1.setY(111);
	cout << p5.getX() << " " << p5.getY() << endl;	
}
