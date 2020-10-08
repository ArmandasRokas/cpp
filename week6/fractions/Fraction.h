#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {

private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;
public:
    // Class constructor
    Fraction(int n, int d);
    // Methods to update the fraction
    void add(Fraction f);
    void mult(Fraction f);
    void div(Fraction f);
    // Display method
    void display(void);
};

#endif 