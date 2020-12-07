//============================================================================
// Name        : live04-constructors.cpp
// Description : Constructors and inheritance
//============================================================================

#include <iostream>

using namespace std;

class Father {
public:
    Father();
    Father(int u, int v);
    virtual void display(void);
    virtual ~Father(){};
protected:
    int x;
private:
    int y;
};

class Son : public Father {
public:
    Son(int u, int v);
    void display(void);
private:
    int z;
};

Father::Father() {
    this->x = 1;
    this->y = 1;
}

Father::Father(int u, int v){
    this->x = u;
    this->y = v;
}

// Note that Son's constructor needs to invoke Father's constructor first,
// in order to initialize the private variable y (that Son cannot access)
Son::Son(int u, int v) : Father(u, 3) {
    this->z = v;
}

void Father::display(void) {
    cout << "x=" << x << ", y=" << y << endl;
}

void Son::display(void) {
    cout << "x=" << x << ", z=" << z << endl;
}

int main(void){
    Father f(1,1);
    Son s(2,2);

    cout << "Father: ";
    f.display();
    
    cout << "Son: ";
    s.display();

    f = s;

    cout << "Father (after executing f=s): ";
    f.display();

    return 0;
}
