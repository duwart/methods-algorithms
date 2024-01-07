#include "../include/falsa_posicao.h"

float funcao1(float a)
{
    return 2 * cos(a) - exp(a) / 2;
}

float falsa_posicao(float a, float b, float prec1, float prec2)
{
    if (b - a < prec1)
    {
        if (fabs(funcao1(a)) < prec2 || fabs(funcao1(b)) < prec2)
        {
            return a;
        }
    }
    float M = funcao1(a);
    float x;
    int i = 1;
    while ((b - a) > prec1)
    {
        x = (a * funcao1(b) - b * funcao1(a)) / (funcao1(b) - funcao1(a));

        i = i + 1;
        if (fabs(funcao1(x)) <= prec2)
        {
            return x;
        }
        if (M * funcao1(x) > 0)
        {
            a = x;
        }
        else
        {
            b = x;
        }
    }
    i = i + 1;
    return (a + b) / 2;
}
