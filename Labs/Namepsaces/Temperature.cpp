#include <iostream>
#include "Temperature.h"

using namespace std;

void temperatures::f2c(temperatures::temperature *t)
{
    float c;
    t->cels = f2c(t->fahr);
}

namespace temperatures
{
    void showTemps(float startF, float endF)
    {
        for (float f = startF; f < endF; f += 2)
        {
            cout << f << "f -> \t" << f2c(f) << endl;
        }
    }
}