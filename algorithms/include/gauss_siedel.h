#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> Gauss_Seidel(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax);