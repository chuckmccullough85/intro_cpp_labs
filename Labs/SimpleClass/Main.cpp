#include <iostream>
#include "Address.h"
using namespace std;
using namespace utility;

int main()
{
    Address addr1;
    addr1.setStreet("123 Easy");
    addr1.setCity("Anytown");
    addr1.setState("TX");
    addr1.setZip("77665");

    cout << addr1.getAddressLabel() << endl;

}