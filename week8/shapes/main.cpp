#include "shapes.h"
#include <iostream>

using namespace std;

int main(){

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
    

    return 0;
}