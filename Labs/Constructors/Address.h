#pragma once
#include <string>
#include <iostream>

namespace utility
{
    using namespace std;

    class Address
    {
    public:
    //    Address() : Address("","", "", "") {}
        
        // OK
        // Address(string street, string city, string state, string zip) 
        //     : street(street), city(city), state(state), zip(zip) {}
        
        // Better
        Address(string street="", string city="", string state="", string zip="") 
        //    : street("123 Easy"), city(), state(), zip()
        {
            setStreet(street);
            setCity(city);
            setState(state);
            setZip(zip);
        }

        ~Address() {cout << "Address destructor: " << getStreet() << endl;}

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
        string street = "123 Easy";
        string city;
        string state;
        string zip;
    };

    inline void foo() {}
}