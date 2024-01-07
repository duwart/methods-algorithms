#pragma once

#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> gauss_jordan(int n, std::vector<std::vector<double>> A, std::vector<double> B);

double gauss_jordan_DET(int n, std::vector<std::vector<double>> A);

std::vector<std::vector<double>> gauss_jordan_MI(int n, std::vector<std::vector<double>> A);