#include "../include/gauss_siedel.h"

std::vector<double> Gauss_Seidel(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax)
{
    double r;
    std::vector<double> x = B;
    std::vector<double> v = B;
    int k;
    double soma;
    double norma;
    for (int i = 0; i < n; i++)
    {
        r = 1 / A.at(i).at(i);
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                A.at(i).at(j) = A.at(i).at(j) * r;
            }
        }
        B.at(i) = B.at(i) * r;
        x.at(i) = 0;
        x.at(i) = B.at(i);
    }
    k = 0;
    while (k < iterMax)
    {
        k = k + 1;
        for (int i = 0; i < n; i++)
        {
            soma = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    soma = soma + A.at(i).at(j) * x.at(j);
                }
            }

            v.at(i) = B.at(i) - soma;
            x.at(i) = B.at(i) - soma;
        }

        // Inicio calcula norma ------------
        double normaNum = 0;
        double normaDen = 0;
        double t;
        for (int i = 0; i < n; i++)
        {
            t = fabs(v.at(i) - x.at(i));
            if (t > normaNum)
            {
                normaNum = t;
            }
            if (fabs(v.at(i)) > normaDen)
            {
                normaDen = fabs(v.at(i));
            }
            x.at(i) = v.at(i);
        }
        norma = normaNum / normaDen;
        // fim calcula norma ------------

        if (norma <= epsilon)
        {
            break;
        }
    }
    return x;
}