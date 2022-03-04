#include <iostream>
#include <cmath>
#include <vector>


std::vector<double> sub_ret(int n, std::vector<std::vector<double>> A ,std::vector<double> B);
std::vector<double> sub_ret(int n, std::vector<std::vector<double>> A ,std::vector<double> B){
	double soma = 0;
	std::vector<double> x;
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	x.at(n-1) = B.at(n-1)/A.at(n-1).at(n-1);
	for(int i = n-2;i>=0;i--){
		soma = 0;
		for(int j = i+1;j<n;j++){
			soma = soma + A.at(i).at(j)*x.at(j);
		}
		x.at(i) = (B.at(i) - soma)/A.at(i).at(i);
	}
	return x;
}

std::vector<double> e_gauss(int n, std::vector<std::vector<double>> A ,std::vector<double> B);
std::vector<double> e_gauss(int n, std::vector<std::vector<double>> A ,std::vector<double> B){
	double m = 0;
	std::vector<double> x;
	for(int k=0; k<n;k++){
		for(int i=k+1;i<n;i++){
			m = - A.at(i).at(k)/A.at(k).at(k);
			A.at(i).at(k) = 0;
			for(int j = k+1;j<n;j++){
				A.at(i).at(j) = A.at(i).at(j) + m*A.at(k).at(j);
			}
			B.at(i) = B.at(i) + m*B.at(k);
		}
	}
	x = sub_ret(n, A, B);
	return x;
}

int main(){
	std::vector<double> L1;
	L1.push_back(20);
	L1.push_back(7);
	L1.push_back(9);
	std::vector<double> L2;
	L2.push_back(7);
	L2.push_back(30);
	L2.push_back(8);
	std::vector<double> L3;
	L3.push_back(8);
	L3.push_back(9);
	L3.push_back(30);
	std::vector<double> B;
	B.push_back(16);
	B.push_back(38);
	B.push_back(38);
	std::vector<std::vector<double>> A;
	A.push_back(L1);
	A.push_back(L2);
	A.push_back(L3);
	std::vector<double> x = e_gauss(3,A,B);

	std::cout <<"x = [ "<< x.at(0) << " "<< x.at(1) << " "<< x.at(2) << " ]\n";

}


