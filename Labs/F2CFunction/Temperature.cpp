#include "Temperature.h"

float f2c(float f)
{
    float c;
    c = (f - 32) * 5.0 / 9.0;
    return c;
}