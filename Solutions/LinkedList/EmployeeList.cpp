#include "EmployeeList.h"
#include "Employee.h"

namespace collections
{
    void list::add(const Employee *e)
    {
        auto n = new node(e);
        if (tail != nullptr)
            tail->right = n;
        else
            head = n;
        tail = n;
    }
}
