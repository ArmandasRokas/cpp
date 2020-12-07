//============================================================================
// Name        : live00-employee.cpp
// Description : Basic inheritance
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    string name;
};

class HourlyEmployee: public Employee {
public:
    HourlyEmployee(string n) { this->name = n; };
    double hourlyFee;
};

class SalariedEmployee: public Employee {
public:
    SalariedEmployee(string n) { this->name = n; };
    double salary;
};

void printName(Employee *e) {
    cout << e->name << endl;
}

int main(void) {
    HourlyEmployee *h = new HourlyEmployee("Alice");
    SalariedEmployee *s = new SalariedEmployee("Bob");
    Employee *e = h;

    printName(h);
    // printName(e);
    printName(s);

    return 0;
}
