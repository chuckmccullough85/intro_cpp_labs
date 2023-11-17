#include <iostream>
#include "Address.h"
using namespace std;
using namespace utility;

int main()
{
    Address addr0;
    Address addr1 ("123 Easy", "Anytown", "TX", "77665");
    cout << addr1.getAddressLabel() << endl;
    {
        Address addr2 ("4 Nested", "Othertown", "TX", "77665");
    }

}