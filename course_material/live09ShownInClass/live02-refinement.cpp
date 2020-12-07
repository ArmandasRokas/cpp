//============================================================================
// Name        : live02-refinement.cpp
// Description : Static method dispatch vs. dynamic method dispatch
//============================================================================

#include <iostream>

using namespace std;

class Father {
public:
    void staticMethod(void) { cout << "Calling Father::staticMethod" << endl; };
    virtual void dynMethod(void) { cout << "Calling Father::dynMethod" << endl; };
};

class Son : public Father {
public:
    void staticMethod(void) { cout << "Calling Son::staticMethod" << endl; };
    virtual void dynMethod(void) { cout << "Calling Son::dynMethod" << endl; };
};

int main(void){
    Son *s = new Son();
    Father *f = s;

    cout << "Static dispatch:" << endl;
    f->staticMethod();
    s->staticMethod();

    cout << "Dynamic dispatch:" << endl;
    f->dynMethod();
    s->dynMethod();

    delete s;
    return 0;
}
