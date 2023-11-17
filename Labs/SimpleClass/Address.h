#pragma once
#include <string>

namespace utility
{
    using namespace std;

    class Address
    {
    public:
        string getAddressLabel() 
        {
            string label;
            label = getStreet();
            label += '\n';
            label += getCity();
            label += ", ";
            label += getState();
            label += "  ";
            label += getZip();
            return label;
        }

        string getStreet()  { return street; }
        void setStreet(string value)
        {
            street = value;
        }
        string getCity()  { return city; }
        void setCity(string value)
        {
            city = value;
        }
        string getState()  { return state; }
        void setState(string value)
        {
            state = value;
        }
        string getZip()  { return zip; }
        void setZip(string value)
        {
            zip = value;
        }

    private:
        string street;
        string city;
        string state;
        string zip;
    };
}