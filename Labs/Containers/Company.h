#include <string>
#include <iostream>
#include <list>
#include "Address.h"
#include "Payable.h"

namespace payroll
{
    using namespace std;
    class Company : public Payable
    {
    public:
        Company(const string& name, const utility::Address &address = utility::Address())
        {
            this->name = name;
            this->address = address;
        }
        string getName() const
        {
            return name;
        }
        void setName(const string& name)
        {
            this->name = name;
        }
        utility::Address getAddress() const
        {
            return address;
        }
        void setAddress(const utility::Address &address)
        {
            this->address = address;
        }
        void hire(Payable *resource)
        {
            resources.push_back(resource);
        }
        double pay() override
        {
            double total = 0;
            for (auto resource : resources)
                total += resource->pay();
            return total;
        }

    private:
        string name;
        utility::Address address;
        std::list<Payable*> resources;
    };

    ostream& operator << (ostream& out, const Company& c)
    {
        out << c.getName() << endl 
            << c.getAddress().getAddressLabel() << endl;
        return out;
    }
}