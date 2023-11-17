#include <string>
#include <iostream>
#include "List.h"
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
            resources.add(resource);
        }
        double pay() override
        {
            double total = 0;
            Payable *e;
            auto it = resources.begin();
            while ((e = it.next()) != nullptr)
                total += e->pay();
            return total;
        }

    private:
        string name;
        utility::Address address;
        collections::list<Payable> resources;
    };

    ostream& operator << (ostream& out, const Company& c)
    {
        out << c.getName() << endl 
            << c.getAddress().getAddressLabel() << endl;
        return out;
    }
}