#include <iostream>
#include <string>
#include "Employee.h"
#include "Address.h"

using namespace std;
using namespace payroll;
using namespace utility;

int main()
{
    Employee bob("Bob", 100);
    bob.setHomeAddress(Address("123 Main St", "Anytown", "NY", "12345"));
    auto bnet = bob.pay();
    cout << "Bob's net pay is " << bnet << endl;

    Employee sue("Sue", 200);
    sue.setHomeAddress(Address("456 Main St", "Anytown", "NY", "12345"));
    auto snet = sue.pay();
    cout << "Sue's net pay is " << snet << endl;
    return 0;
}