#include <iostream>

int main()
{
    float f = 93;
    float c = 0;
    for (f = 32; f <= 212; f++)
    {
        c = (f - 32) * 5.0 / 9.0;
        std::cout << c << std::endl;
    }
    return 0;
}