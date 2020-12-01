#include "shapes.h"
#include <iostream>

using namespace std;

int main(){
    /*
    //Rectangle s(3.0,2.0);
    Circle circle(2.0);
    Shape * s = &circle;
   //Square s(3.0);
    cout << "Height: " << s->height() << ", Width: " << s->width() << endl;
    cout << "Rotating..." << endl;
    s->rotate(); 
    cout << "Height: " << s->height() << ", Width: " << s->width() << endl;
    cout << "Area: " << s->area() << endl;
    cout << "Perimeter: " << s->perimeter() << endl;
    */
    Rectangle r1(10,5);
    Rectangle r2(11,6);
    Rectangle r3 = r1+r2;
    cout << "Height: " << r3.height() << ", Width: " << r3.width() << endl;

    return 0;
}