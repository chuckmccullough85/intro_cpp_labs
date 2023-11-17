#pragma once

namespace temperatures
{

    struct temperature
    {
        float fahr;
        float cels;
    };

    void f2c(temperature *t);
    void showTemps(float startF = 32, float endF = 212);

    inline float f2c(float f)
    {
        return (f - 32) * 5.0 / 9.0;
    }
}