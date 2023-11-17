#include <iostream>
#include "Address.h"
#include "Employee.h"
#include "Company.h"
#include "Contractor.h"
using namespace std;
using namespace payroll;


int main()
{
    try {
    Employee bad("Bad Dude", -10);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    Company acme("Acme, Inc.");
    Employee e1("John", 10000); 
    Employee e2("Mary", 12000);
    Employee e3("Bob", 8000);
    Employee e4("Alice", 9000);
    Contractor c1("Joe", 50);
    Company sales("Sales department");

    acme.hire(&e1);
    acme.hire(&e2);
    acme.hire(&e3);
    acme.hire(&e4);   
    acme.hire(&sales); 

    cout << "Total payroll: " << acme.pay() << endl;

    cout << e1 << endl;
    cout << acme << endl;
}