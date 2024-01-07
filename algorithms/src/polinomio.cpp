#include "../include/polinomio.h"

float polinomio(float x, int itmax, float prec1, float prec2)
{
    float a[4] = {3, 9, 0, 1};
    float deltax = x;
    float b = 0;
    float c = 0;
    for (int k = 0; k < itmax; k++)
    {
        b = a[3];
        c = b + c * x;
        for (int i = 2; i > 0; i--)
        {
            b = a[i] + b * x;
            c = b + c * x;
        }
        b = a[0] + b * x;
        if (fabs(b) <= prec1)
        {
            return x;
        }
        deltax = b / c;

        x = x - deltax;
        if (fabs(deltax) <= prec2)
        {
            return x;
        }
    }
    return x;
}