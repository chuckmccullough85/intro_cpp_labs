#include <iostream>
#include "Address.h"
#include "Employee.h"
#include "EmployeeList.h"
using namespace std;
using namespace payroll;
using namespace collections;

void foo(list x){}

int main()
{
    list mylist;
    Employee e1("John", 100000); 
    Employee e2("Mary", 120000);
    Employee e3("Bob", 80000);
    Employee e4("Alice", 90000);
    mylist.add(&e1);
    mylist.add(&e2);
    mylist.add(&e3);
    mylist.add(&e4);

    //foo(mylist);

    payroll::Employee *e = nullptr;
    auto cursor = mylist.begin();
    while((e = (payroll::Employee*)cursor.next()) != nullptr)
    {
        std::cout << e->getName() << " " << 
            e->pay() << std::endl;
    }

}