#include <iostream>
#include "Temperature.h"

void f2c(temperature* t)
{
    float c;
    t->cels = f2c(t->fahr);
}

void showTemps(float startF, float endF)
{
    for (float f = startF; f < endF; f += 2)
    {
        std::cout << f << "f -> \t" << f2c(f) << std::endl;
    }
}