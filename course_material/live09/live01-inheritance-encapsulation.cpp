//============================================================================
// Name        : live01-inheritance-encapsulation.cpp
// Description : Encapsulation of superclass members and inheritance
//============================================================================

class A {
public:
    int x; // accessible to everyone
    int getz(); // accessible to everyone
protected:
    int y; // accessible to all derived classes (A, B, C, D)
private:
    int z; // accessible only to A
};

class B : public A {
    // x is public
    // getz() is public
    // y is protected
    // z is not accessible from B
public:
    int gety();
};

class C : protected A {
    // x is protected
    // getz() is protected
    // y is protected
    // z is not accessible from C
public:
    int gety();
};

class D : private A {
    // x is private
    // getz() is private
    // y is private
    // z is not accessible from D
public:
    int gety();
};

int A::getz() {
    return z;
};

int B::gety() {
    return y;
}

int C::gety() {
    return y;
}

int D::gety() {
    return y;
}

int main(){
    A a;
    a.x = 0;
    // a.y = 0; // Does not compile

    B b;
    b.x = 0;
    b.getz();

    C c;
    // c.x = 0; // Does not compile
    // c.getz(); // Does not compile

    D d;
    // d.x = 0; // Does not compile
    // d.getz(); // Does not compile

    return 0;
}
