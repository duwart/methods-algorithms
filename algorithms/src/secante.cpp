#include "../include/secante.h"

float funcao4(float a)
{
    return 2 * cos(a) - exp(a) / 2;
}

float secante(float a, float b, float prec1, float prec2)
{

    if (fabs(funcao4(a)) < prec1 || fabs(b - a) < prec2)
    {
        return a;
    }
    int k = 1;
    float x;
    x = b - (funcao4(b) / (funcao4(b) - funcao4(a))) * (b - a);
    while (!(fabs(funcao4(x)) < prec1 || fabs(x - b) < prec2))
    {
        a = b;
        b = x;
        k = k + 1;
        x = b - (funcao4(b) / (funcao4(b) - funcao4(a))) * (b - a);
    }
    return x;
}
