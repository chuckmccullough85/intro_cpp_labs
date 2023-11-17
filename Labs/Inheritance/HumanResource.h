#pragma once

#include <string>
#include "Address.h"

namespace payroll
{
    class HumanResource
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

        virtual double pay() = 0;

    private:
        std::string name_;
        utility::Address address_;
    };
}