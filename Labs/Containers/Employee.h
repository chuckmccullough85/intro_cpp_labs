#pragma once
#include <string>
#include "HumanResource.h"

namespace payroll
{
    constexpr double TAX_RATE = 0.15;
    class Employee : public HumanResource
    {
    public:
        Employee(const std::string &name, double salary) 
        : HumanResource(name) 
        {
            setSalary(salary);
        }

        double getSalary() const
        {
            return salary_;
        }
        void setSalary(double salary)
        {
            if (salary < 10 || salary > 100'000)
                throw std::invalid_argument("Invalid salary: " + std::to_string(salary));
            salary_ = salary;
        }

        double getYtdSalary() const
        {
            return ytdSalary_;
        }
        double pay() override
        {
            ytdSalary_ += salary_;
            auto tax = ytdSalary_ * TAX_RATE;
            return salary_ - tax;
        }

        bool operator == (const Employee& rhs) const
        {
            return getName() == rhs.getName() && salary_ == rhs.salary_;
        }
        bool operator != (const Employee& rhs) const
        {
            return !(*this == rhs);
        }

    private:
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