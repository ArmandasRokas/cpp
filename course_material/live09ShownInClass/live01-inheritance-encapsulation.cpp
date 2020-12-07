//============================================================================
// Name        : live01-inheritance-encapsulation.cpp
// Description : Encapsulation of superclass members and inheritance
//============================================================================

class A {
public:
    int x; // accessible to everyone
    int getz() { return z; }; // accessible to everyone
protected:
    int y; // accessible to all derived classes (A, B, C, D)
private:
    int z; // accessible only to A
};

class B : public A {
    // x remains public
    // getz() remains public
    // y remains protected
    // z is NOT accessible
public:
    int gety() { return this->y; };
};

class C : protected A {
    // x becomes protected
    // getz() becomes protected
    // y remains protected
    // z is NOT accessible
public:
    int gety() { return y; };
};

class D : private A {
    // x becomes private
    // getz() becomes private
    // y becomes private
    // z is NOT accessible
public:
    int gety() { return y; };
};

int main(){
    B b = B();
    // b.y = 42; // does not compile
    b.gety();
    b.getz();
    b.x = 42;

    C c = C();
    // c.x = 42; // does not compile
    // c.getz(); // does not compile
    c.gety();

    return 0;
}
