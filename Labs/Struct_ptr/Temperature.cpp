#include "Temperature.h"

void f2c(temperature* t)
{
    t->cels = (t->fahr - 32) * 5.0 / 9.0;
}