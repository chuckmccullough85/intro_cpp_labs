#include <iostream>

int main()
{
    float f = 32;
    float c = 0;
    while (f <= 212)
    {
        c = (f - 32) * 5.0 / 9.0;
        std::cout << c ;
        if (f < 40) std::cout << " cold" << std::endl;
        else if (f>115) std::cout << " hot" << std::endl;
        else std::cout << std::endl;
        
        f += 2;
    }
    return 0;
}