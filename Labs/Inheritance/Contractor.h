#include "HumanResource.h"

namespace payroll
{
    class Contractor : public HumanResource
    {
        public:
        Contractor(const std::string &name, double rate)
        : HumanResource(name), rate_(rate) {}

        double pay() override
        {
            return rate_ * 40;
        }

        private:
        double rate_;
    };
}