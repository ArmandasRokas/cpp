#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int n, int d){
    this->numerator = n;
    this->denominator = d;
}

void Fraction::display(void){

    // Simplify
    for (int i = this->denominator * this->numerator; i > 1; i--) {  
        if ((this->denominator % i == 0) && (this->numerator % i == 0)) {  
            this->denominator /= i;  
            this->numerator /= i;  
        }         
    }
    std::cout << this->numerator << " / " << this->denominator << std::endl;
}

void Fraction::add(Fraction f){

    if(this->denominator != f.denominator){
        this->numerator *= f.denominator;
        f.numerator *= this->denominator;
        this->denominator *= f.denominator;
        this->numerator += f.numerator;
    } else {
        this->numerator += f.numerator;
    }
}

void Fraction::mult(Fraction f){
    this->numerator *= f.numerator;
    this->denominator *= f.denominator;
}

void Fraction::div(Fraction f){
    this->numerator *= f.denominator;
    this->denominator *= f.numerator;
}