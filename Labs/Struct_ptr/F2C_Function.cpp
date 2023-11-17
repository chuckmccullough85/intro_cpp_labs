#include <iostream>
#include "Temperature.h"

int main()
{
    float f = 32;

    while (f <= 212)
    {
        temperature t = {f,0};
        t.fahr = f;
        f2c(&t);
        std::cout << t.cels ;
        if (f < 40) std::cout << " cold" << std::endl;
        else if (f>115) std::cout << " hot" << std::endl;
        else std::cout << std::endl;
        
        f += 2;
    }
    return 0;
}


