#include "../include/gauss_jordan.h"

std::vector<double> gauss_jordan(int n, std::vector<std::vector<double>> A, std::vector<double> B)
{
    for (int k = 0; k < n; k++)
    {
        for (int j = k + 1; j < n; j++)
        {
            A.at(k).at(j) = A.at(k).at(j) / A.at(k).at(k);
        }
        B.at(k) = B.at(k) / A.at(k).at(k);
        A.at(k).at(k) = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                for (int j = k + 1; j < n; j++)
                {
                    A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k) * A.at(k).at(j);
                }
                B.at(i) = B.at(i) - A.at(i).at(k) * B.at(k);
                A.at(i).at(k) = 0;
            }
        }
    }

    return B;
}

double gauss_jordan_DET(int n, std::vector<std::vector<double>> A)
{
    std::vector<double> x;
    double det = 1;
    for (int k = 0; k < n; k++)
    {
        for (int j = k + 1; j < n; j++)
        {
            A.at(k).at(j) = A.at(k).at(j) / A.at(k).at(k);
        }
        // A.at(k).at(k) = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                for (int j = k + 1; j < n; j++)
                {
                    A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k) * A.at(k).at(j);
                }
                A.at(i).at(k) = 0;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        det = det * A.at(j).at(j);
    }

    return det;
}

std::vector<std::vector<double>> gauss_jordan_MI(int n, std::vector<std::vector<double>> A)
{
    std::vector<std::vector<double>> AI = A;
    for (int l = 0; l < n; l++)
    {
        for (int m = 0; m < n; m++)
        {
            if (m == l)
            {
                AI.at(l).at(m) = 1;
            }
            else
            {
                AI.at(l).at(m) = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = k + 1; j < n; j++)
        {
            AI.at(k).at(j) = AI.at(k).at(j) / A.at(k).at(k);
            A.at(k).at(j) = A.at(k).at(j) / A.at(k).at(k);
        }
        for (int c = 0; c < k; c++)
        {
            AI.at(k).at(c) = AI.at(k).at(c) / A.at(k).at(k);
        }
        AI.at(k).at(k) = AI.at(k).at(k) / A.at(k).at(k);
        A.at(k).at(k) = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != k)
            {
                for (int j = k + 1; j < n; j++)
                {
                    A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k) * A.at(k).at(j);
                    AI.at(i).at(j) = AI.at(i).at(j) - AI.at(i).at(k) * A.at(k).at(j);
                }
                for (int j = k - 1; j >= 0; j--)
                {
                    AI.at(i).at(j) = AI.at(i).at(j) - A.at(i).at(k) * AI.at(k).at(j);
                }
                AI.at(i).at(k) = -A.at(i).at(k) * AI.at(k).at(k);
                A.at(i).at(k) = 0;
            }
        }
    }

    return AI;
}
