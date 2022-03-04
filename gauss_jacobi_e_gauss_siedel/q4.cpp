#include <iostream>
#include <cmath>
#include <vector>


double calcula_norma(int n, std::vector<double> x, std::vector<double> v);
double calcula_norma(int n, std::vector<double> x, std::vector<double> v){
    double normaNum = 0;
    double normaDen = 0;
    double t;
    for(int i=0;i<n;i++){
        t = fabs(v.at(i)-x.at(i));
        if (t > normaNum){
            normaNum = t;
        }
        if (fabs(v.at(i))> normaDen){
            normaDen = fabs(v.at(i));
        }
        x.at(i) = v.at(i);
    }
    //return x;
    return normaNum/normaDen;
}

std::vector<double> Gauss_Jacobi(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax);
std::vector<double> Gauss_Jacobi(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax){
    double r;
    std::vector<double> x = B;
    std::vector<double> v = B;
    int k;
    double soma;
    double norma;
    for(int i = 0;i<n;i++){
        r = 1/A.at(i).at(i);
        for(int j=0;j<n;j++){
            if (i != j){
                A.at(i).at(j) = A.at(i).at(j)*r;
            }
        }
        B.at(i) = B.at(i)*r;
        x.at(i) = B.at(i);
    }
    k = 0;
    while(k<iterMax){
        k = k+1;
        for(int i=0;i<n;i++){
            soma = 0;
            for(int j=0;j<n;j++){
                if(i != j){
                    soma = soma + A.at(i).at(j)*x.at(j);
                }
            }
            v.at(i) = B.at(i) - soma;
        }
        
        // Inicio calcula norma ------------
        double normaNum = 0;
        double normaDen = 0;
        double t;
        for(int i=0;i<n;i++){
            t = fabs(v.at(i)-x.at(i));
            if (t > normaNum){
                normaNum = t;
            }
            if (fabs(v.at(i))> normaDen){
                normaDen = fabs(v.at(i));
            }
            x.at(i) = v.at(i);
        }
        norma = normaNum/normaDen;
        // fim calcula norma ------------

        if(norma <= epsilon){
            break;
        }
    }
    return x;
}

std::vector<double> Gauss_Seidel(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax);
std::vector<double> Gauss_Seidel(int n, std::vector<std::vector<double>> A, std::vector<double> B, double epsilon, int iterMax){
    double r;
    std::vector<double> x = B;
    std::vector<double> v = B;
    int k;
    double soma;
    double norma;
    for(int i = 0;i<n;i++){
        r = 1/A.at(i).at(i);
        for(int j=0;j<n;j++){
            if (i != j){
                A.at(i).at(j) = A.at(i).at(j)*r;
            }
        }
        B.at(i) = B.at(i)*r;
        x.at(i) = 0;
        x.at(i) = B.at(i);
    }
    k = 0;
    while(k<iterMax){
        k = k+1;
        for(int i=0;i<n;i++){
            soma = 0;
            for(int j=0;j<n;j++){
                if(i != j){
                    soma = soma + A.at(i).at(j)*x.at(j);
                }
            }
            

            v.at(i) = B.at(i) - soma;
            x.at(i) = B.at(i) - soma;
            
        }
        
        // Inicio calcula norma ------------
        double normaNum = 0;
        double normaDen = 0;
        double t;
        for(int i=0;i<n;i++){
            t = fabs(v.at(i)-x.at(i));
            if (t > normaNum){
                normaNum = t;
            }
            if (fabs(v.at(i))> normaDen){
                normaDen = fabs(v.at(i));
            }
            x.at(i) = v.at(i);
        }
        norma = normaNum/normaDen;
        // fim calcula norma ------------

        if(norma <= epsilon){
            break;
        }
    }
    return x;
}

int main(){
    std::vector<double> L1;
    L1.push_back(10);
    L1.push_back(2);
    L1.push_back(2);
    std::vector<double> L2;
    L2.push_back(1);
    L2.push_back(10);
    L2.push_back(2);
    std::vector<double> L3;
    L3.push_back(2);
    L3.push_back(-7);
    L3.push_back(-10);
    std::vector<double> B;
    B.push_back(28);
    B.push_back(7);
    B.push_back(-17);
    std::vector<std::vector<double>> A;
    A.push_back(L1);
    A.push_back(L2);
    A.push_back(L3);
    std::vector<double> x = Gauss_Jacobi(3,A,B,0.5, 30);

    std::cout <<"Gauss_Jacobi: [ "<< x.at(0) << " "<< x.at(1) << " "<< x.at(2) << " ]\n";

    x = Gauss_Seidel(3,A,B,0.5, 30);

    std::cout <<"Gauss_Seidel: [ "<< x.at(0) << " "<< x.at(1) << " "<< x.at(2) << " ]\n";
}


