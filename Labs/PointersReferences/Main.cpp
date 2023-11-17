#include <iostream>
using namespace std;
void DisplayInt(int value)
{
    cout << "DisplayInt: " << value 
    << " at address: " << &value << endl;
    value++;
}

void DisplayIntRef(int& value)
{
    cout << "DisplayIntRef: " << value 
    << " at address: " << &value << endl;
    value++;
}

void DisplayIntPointer(int* value)
{
    cout << "DisplayIntPointer: " << *value 
    << " at address: " << value << endl;
    (*value)++;
}

int main()
{
    int value = 5;
    cout << "Value: " << value 
    << " at address: " << &value << endl;

    DisplayInt(value);
    DisplayIntRef(value);
    DisplayIntPointer(&value);

    cout << "End Value: " << value << endl;
    return 0;
}
