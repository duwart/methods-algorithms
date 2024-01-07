#include "../include/newton_rapson.h"

float funcao5(float a)
{
    return 2 * cos(a) - exp(a) / 2;
}

float funcaoDerivada(float a)
{
    return -2 * sin(a) + exp(a) * (-1 / 2);
}

float newton_rapson(float x, float prec1, float prec2)
{
    if (fabs(funcao5(x)) < prec1)
    {
        return x;
    }
    int k = 1;
    float x1 = x - funcao5(x) / funcaoDerivada(x);
    while (!(fabs(funcao5(x1)) < prec1 || fabs(x1 - x) < prec2))
    {
        x = x1;
        k = k + 1;
        x1 = x - funcao5(x) / funcaoDerivada(x);
    }
    return x;
}
