#ifndef __shapes__
#define __shapes__


class Shape{
    public:
        Shape(double h, double w);
        virtual double area(); // virtual ensures that the overrided methods is called in the runtime 
        virtual double perimeter();
        virtual double height();
        virtual double width();
        void rotate();
    protected: 
        double w;
        double h;
};

class Rectangle: public Shape{
    public:
        Rectangle(double h, double w);
};

class Square: public Shape{
    public:
        Square(double w);
};

class Circle: public Shape{
    public:
        Circle(double radius);
        double area() override;  // override is not required but it helps to avoid bug. Thus it shows that it should override a function, that means there should be a function a base class with the same parameters and return type
        double perimeter() override;
        double height() override;
        double width() override;
};

#endif