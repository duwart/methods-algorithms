#include <iostream>
#include <cmath>
#include <vector>

std::vector<double> sub_ret2(int n, std::vector<std::vector<double>> A, std::vector<double> B);

double *pivo(std::vector<std::vector<double>> A, int k, int n);

std::vector<std::vector<double>> permuta(std::vector<double> p, std::vector<std::vector<double>> A, int k, int r, int n);

std::vector<double> subst_sucess_mod(int n, std::vector<std::vector<double>> A, std::vector<double> B);

std::vector<double> LU_piv_parc(int n, std::vector<std::vector<double>> A, std::vector<double> B);