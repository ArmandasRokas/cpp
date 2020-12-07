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
    virtual ~Father() {};

};

class Son : public Father {
public:
    void staticMethod(void) { cout << "Calling Son::staticMethod" << endl; };
    void dynMethod(void) { cout << "Calling Son::dynMethod" << endl; };
};

class Nephew : public Son {
public:
    void staticMethod(void) { cout << "Calling Nephew::staticMethod" << endl; };
    void dynMethod(void) { cout << "Calling Nephew::dynMethod" << endl; };
};

void testFatherSon();
void testFatherSonNephew();

int main(void){
    testFatherSon();
    cout <<"" << endl;
    testFatherSonNephew();
}

void testFatherSon(){
    cout << "###############" << endl;
    cout << "Test Father-Son" << endl;
    cout << "###############" << endl;
    Son *s = new Son();
    Father *p = s;

    // Static dispatch of 'staticMethod': based on p’s type
    cout <<"Static dispatch" << endl;
    s->staticMethod();  // calls Son::staticMethod()
    p->staticMethod();  // calls Father::staticMethod()

    // Dynamic dispatch: based on actual type of object pointed by p
    cout <<"\nDynamic dispatch" << endl;
    s->dynMethod();  // calls Son::dynMethod()
    p->dynMethod();  // calls Son::dynMethod()
}

void testFatherSonNephew(){
    cout << "######################" << endl;
    cout << "Test Father-Son-Nephew" << endl;
    cout << "######################" << endl;
    Nephew *n = new Nephew();
    Son *s = n;
    Father *p = s;

    // Static dispatch of 'staticMethod': based on p’s type
    cout <<"Static dispatch" << endl;
    n->staticMethod();  // calls Nephew::staticMethod()
    s->staticMethod();  // calls Son::staticMethod()
    p->staticMethod();  // calls Father::staticMethod()

    // Dynamic dispatch: based on actual type of object pointed by p
    cout <<"\nDynamic dispatch" << endl;
    n->dynMethod();  // calls Nephew::dynMethod()
    s->dynMethod();  // calls Nephew::dynMethod()
    p->dynMethod();  // calls Nephew::dynMethod()
}
