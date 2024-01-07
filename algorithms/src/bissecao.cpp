#include "../include/bissecao.h"

float funcao2(float a)
{
    return 2 * cos(a) - exp(a) / 2;
}

float bissecao(float a, float b, float prec)
{
    int i = 1;
    if (b - a < prec)
    {

        return (b + a) / 2;
    }
    float M = funcao2(a);
    float x;
    while ((b - a) > prec)
    {

        i = i + 1;
        x = (a + b) / 2;
        if (M * funcao2(x) > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    return (a + b) / 2;
}