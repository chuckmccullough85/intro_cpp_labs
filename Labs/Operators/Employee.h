#pragma once
#include <string>
#include "Address.h"

namespace payroll
{
    constexpr double TAX_RATE = 0.15;
    class Employee
    {
    public:
        Employee(const std::string &name, double salary) : name_(name), salary_(salary) {}

        std::string getName() const
        {
            return name_;
        }
        double getSalary() const
        {
            return salary_;
        }
        void setSalary(double salary)
        {
            salary_ = salary;
        }
        void setHomeAddress(const utility::Address &address)
        {
            address_ = address;
        }
        utility::Address getHomeAddress() const
        {
            return address_;
        }
        double getYtdSalary() const
        {
            return ytdSalary_;
        }
        double pay() 
        {
            ytdSalary_ += salary_;
            auto tax = ytdSalary_ * TAX_RATE;
            return salary_ - tax;
        }

        bool operator == (const Employee& rhs) const
        {
            return name_ == rhs.name_ && salary_ == rhs.salary_;
        }
        bool operator != (const Employee& rhs) const
        {
            return !(*this == rhs);
        }

    private:
        std::string name_;
        utility::Address address_;
        double salary_;
        double ytdSalary_ = 0;
    };

    inline std::ostream& operator << (std::ostream& out, const Employee& e)
    {
        out << e.getName() << std::endl 
            << e.getHomeAddress().getAddressLabel() << std::endl
            << "YTD Salary: " << e.getYtdSalary() << std::endl;
        return out;
    }
}