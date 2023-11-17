#pragma once

#include <string>
#include "Address.h"
#include "Payable.h"

namespace payroll
{
    class HumanResource : public Payable
    {
    public:
        HumanResource(const std::string &name) : name_(name) {}
        std::string getName() const
        {
            return name_;
        }

        void setHomeAddress(const utility::Address &address)
        {
            address_ = address;
        }
        utility::Address getHomeAddress() const
        {
            return address_;
        }

    private:
        std::string name_;
        utility::Address address_;
    };
}