#pragma once

#include <string>
#include <regex>
#include <stdexcept>
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
        void setName(const std::string &name)
        {
            if (!std::regex_match(name, std::regex("[A-Z][a-z]+ [A-Z][a-z]+")))
                throw std::invalid_argument("Invalid name: " + name);
            name_ = name;
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