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
    HourlyEmployee(string n) { this-> name = n; }
    double hourlyFee;
};

class CommissionedEmployee: public Employee {
public:
    CommissionedEmployee(string n) { this-> name = n; }
    double commission;
};

class SalariedEmployee: public Employee {
public:
    SalariedEmployee(string n) { this-> name = n; }
    double salary;
};

int main(void) {
    HourlyEmployee h = HourlyEmployee("Alice");
    CommissionedEmployee c = CommissionedEmployee("Bob");
    SalariedEmployee s = SalariedEmployee("Carol");

    cout << "The employee names are: ";
    cout << h.name << ", " << c.name << ", " << s.name << endl;
}
