#include "algorithms/include/falsa_posicao.h"
#include "algorithms/include/bissecao.h"
#include "algorithms/include/gauss_jordan.h"
#include "algorithms/include/gauss_siedel.h"
#include "algorithms/include/gauss_jacobi.h"
#include "algorithms/include/LU_piv_parc.h"
#include "algorithms/include/ponto_fixo.h"
#include "algorithms/include/polinomio.h"
#include "algorithms/include/e_gauss.h"
#include "algorithms/include/newton_rapson.h"
#include "algorithms/include/secante.h"

#define M_PI 3.14

int main()
{

    std::cout << "\nMetodo da bissecao: " << bissecao(M_PI / 4, M_PI / 2, 0.0001) << "\n";
    std::cout << "Metodo da falsa posicao: " << falsa_posicao(M_PI / 4, M_PI / 2, 0.0001, 0.0001) << "\n";

    std::vector<double> L1;
    L1.push_back(20);
    L1.push_back(7);
    L1.push_back(9);
    std::vector<double> L2;
    L2.push_back(7);
    L2.push_back(30);
    L2.push_back(8);
    std::vector<double> L3;
    L3.push_back(9);
    L3.push_back(8);
    L3.push_back(30);
    std::vector<double> B;
    B.push_back(16);
    B.push_back(38);
    B.push_back(38);
    std::vector<std::vector<double>> A;
    A.push_back(L1);
    A.push_back(L2);
    A.push_back(L3);

    std::vector<double> x = gauss_jordan(3, A, B);

    double det = gauss_jordan_DET(3, A);

    std::vector<std::vector<double>> AI = gauss_jordan_MI(3, A);

    std::cout << "x = [ " << x.at(0) << " " << x.at(1) << " " << x.at(2) << " ]\n\n";

    std::cout << "Matriz Inversa\n"
              << AI.at(0).at(0) << " " << AI.at(0).at(1) << " " << AI.at(0).at(2) << "\n"
              << AI.at(1).at(0) << " " << AI.at(1).at(1) << " " << AI.at(1).at(2) << "\n"
              << AI.at(2).at(0) << " " << AI.at(2).at(1) << " " << AI.at(2).at(2) << "\n\n";

    // No determinante não precisamos do B, logo, podemos remover
    std::cout << "Determinante = " << det << "\n";

    x = Gauss_Jacobi(3, A, B, 0.5, 30);

    std::cout << "Gauss_Jacobi: [ " << x.at(0) << " " << x.at(1) << " " << x.at(2) << " ]\n";

    x = Gauss_Seidel(3, A, B, 0.5, 30);

    std::cout << "Gauss_Seidel: [ " << x.at(0) << " " << x.at(1) << " " << x.at(2) << " ]\n";

    x = LU_piv_parc(3, A, B);

    std::cout << "x = [ " << x.at(0) << " " << x.at(1) << " " << x.at(2) << " ]\n";

    std::cout << "\nMetodo do ponto fixo: " << ponto_fixo(0.5, 0.0001, 0.0001) << "\n";
    std::cout << "Metodo do Polinomio: " << polinomio(0.5, 20, 0.0001, 0.0001) << "\n";

    x = e_gauss(3, A, B);

    std::cout << "x = [ " << x.at(0) << " " << x.at(1) << " " << x.at(2) << " ]\n";

    std::cout << "\nMetodo da Newton-Rapson: " << newton_rapson(1, 0.0001, 0.0001) << "\n";
    std::cout << "Metodo da Secante: " << secante(0.5, 1, 0.0001, 0.0001) << "\n";
}