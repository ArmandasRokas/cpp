#include <iostream>
#include "ex04-library.h"

using namespace std;

// Exercise 4 (a)
template <class C>
Monoid<C>::Monoid(C constant){
    this->constant = constant;
    this->m1 = nullptr;
    this->m2 = nullptr;
}

// Exercise 4 (b)
template <class C>
Monoid<C>::Monoid(Monoid<C> & m1, Monoid<C> & m2){
    this->m1 = new Monoid<C>(m1);
    this->m2 = new Monoid<C>(m2);
}

// Exercise 4 (c)
template <class C>
Monoid<C>::Monoid(Monoid & m){
    this->constant = m.constant;
    this->m1 = m.m1;
    this->m2 = m.m2;
}

// Exercise 4 (d)
template <class C>
Monoid<C> Monoid<C>::operator*(Monoid<C> & m) 
{
    // return Monoid<C> (*this, m);// Why can't I just do like this? https://stackoverflow.com/questions/32457686/returning-a-new-object-by-reference
    // Monoid<C> m3 = Monoid<C>(*this,m) // Or this???
    Monoid<C> m3(*this,m);
    return m3;
}

// Exercise 4 (e)
template <class C>
C Monoid<C>::eval(C (*f)(C,C)){
    if(m1==nullptr){
        return this->constant;
    }
    return f(this->m1->eval(f),this->m2->eval(f));
}

// Do not modify
template <class C>
void Monoid<C>::print(void){
    if (m1 == nullptr) cout << constant ;
    else {
        m1->print();
        cout << " * " ;
        m2->print();
    }
}

// Do not modify
template class Monoid<string>;
template class Monoid<unsigned int>;
