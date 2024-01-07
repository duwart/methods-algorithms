#include "../include/ponto_fixo.h"

float funcao3(float a)
{
    return pow(a, 3) - 9 * a + 3;
}

float phi(float a)
{
    return (-pow(a, 3) - 3) / (-9);
}

float ponto_fixo(float x0, float prec1, float prec2)
{
    if (fabs(funcao3(x0)) < prec1)
    {
        return x0;
    }
    int k = 1;
    float x = phi(x0);
    while (!(fabs(funcao3(x)) < prec1 || fabs(x - x0) < prec2))
    {
        x0 = x;
        k = k + 1;
        x = phi(x0);
    }
    return x;
}