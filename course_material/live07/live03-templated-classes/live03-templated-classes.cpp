//============================================================================
// Name        : live03-templated-classes.cpp
// Description : An example of templated class with two parameters
//============================================================================

#include <iostream>
#include <vector>

// Example based on pairs
// see http://www.cplusplus.com/reference/utility/pair/

using namespace std;

template <class A, class B>
class Pair {

public:
    Pair(A a, B b);
    A first(void);
    B second(void);
    Pair<B,A> flip(void);
    Pair<A,B> & operator=(Pair<A,B> & p);
    void display(void);

private:
    A a;
    B b;

};

template <class A, class B>
Pair<A,B>::Pair(A a, B c){
    this->a = a;
    (*this).a =a;
    //this->b = b;
    this->b = c;
}

template <class A, class B>
A Pair<A,B>::first(void){
    return a;
}

template <class A, class B>
B Pair<A,B>::second(void){
    return b;
}

template <class A, class B>
Pair<B,A> Pair<A,B>::flip(void){
    Pair<B,A> p(b,a);
    return p;
}

template <class A, class B>
Pair<A,B> & Pair<A,B>::operator=(Pair<A,B> & p){
    a = p.first();
    b = p.second();
}

template <class A, class B>
void Pair<A,B>::display(void){
    cout << "<" << a << "," << b << ">" << endl;
}

// some templated free functions for pairs

// test if two pairs can be matched/plugged
template <class A, class B, class C>
bool match(Pair<A,B> p, Pair<B,C> q){
    return (p.second() == q.first());
}

// join a pair by taking the first component of the first pair
// and the second component of the second pair
template <class A, class B, class C>
Pair<A,C> join(Pair<A,B> p, Pair<B,C> q){
    Pair<A,C> r(p.first(),q.second());
    return r;
}

int main(void){

    Pair<string,int> a("Alice",1);
    Pair<string,int> b("Bob",2);

    // Pair<vector<int>,int> X(a,2);

    Pair<int,int> likes(1,2);
    vector<int> v;
    // Pair<vector<int>,int> X(v,1);

    a.display();
    b.display();
    likes.display();

    if( match<string,int,int>(a,likes)
       && match<int,int,string>(likes,b.flip()) ) {
        Pair<string,string> gossip = join<string,int,string>(a,b.flip());
        cout << "Gossip alert: ";
        gossip.display();
        cout << endl;
    }
    cout << endl;

    return 0;
}



