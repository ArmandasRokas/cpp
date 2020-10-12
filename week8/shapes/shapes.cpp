#include "shapes.h"
//#include <math.h>

# define PI           3.14159265358979323846  /* pi */

Shape::Shape(double h, double w){
    this->w = w;
    this->h = h;
}

double Shape::height(){
    return this->h;
}
double Shape::width(){
    return this->w;
}

void Shape::rotate(){
    double tempHeight = this->h;
    this->h = this->w;
    this->w = tempHeight;
}

double Shape::area(){
    return this->w * this->h;
}

double Shape::perimeter(){
    return 2*(this->h + this->w);
}

Rectangle::Rectangle(double h, double w): Shape(h,w){}
Square::Square(double w): Shape(w,w){}


Circle::Circle(double radius):Shape(radius,radius){}

double Circle::area(){
    //return M_PI*this->h*this->w;
    return Shape::area()*PI;
}

double Circle::perimeter(){
    return 2*PI*this->h;
}

double Circle::width(){
    return this->w*2;
}


double Circle::height(){
    return this->h*2;
}
