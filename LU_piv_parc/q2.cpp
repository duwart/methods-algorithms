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

double* pivo(std::vector<std::vector<double>> A ,int k, int n);
double* pivo(std::vector<std::vector<double>> A ,int k, int n){
	double* pv;
	pv = new double[2];
	pv[0] = fabs(A.at(k).at(k));
	pv[1] = k;
	for(int i=k+1;i<n;i++){
		if (fabs(A.at(i).at(k))>pv[0]) {
			pv[0] = fabs(A.at(i).at(k));
			pv[1] = i;
		}
	}
	return pv;
}

std::vector<std::vector<double>> permuta(std::vector<double> p, std::vector<std::vector<double>> A ,int k,int r, int n);
std::vector<std::vector<double>> permuta(std::vector<double> p, std::vector<std::vector<double>> A ,int k,int r, int n){
	double aux = p.at(k);
	p.at(k) = p.at(r);
	p.at(r) = aux;
	for (int j=0;j<n;j++){
		aux = A.at(k).at(j);
		A.at(k).at(j) = A.at(r).at(j);
		A.at(r).at(j) = aux;
	}
	return A;
}

std::vector<double> subst_sucess_mod(int n, std::vector<std::vector<double>> A ,std::vector<double> B);
std::vector<double> subst_sucess_mod(int n, std::vector<std::vector<double>> A ,std::vector<double> B){
	double soma = 0;
	std::vector<double> x;
	x.push_back(0);
	x.push_back(0);
	x.push_back(0);
	//x.at(n-1) = B.at(n-1)/A.at(n-1).at(n-1);
	for(int i = 0;i<n;i++){
		soma = 0;
		for(int j = 0;j<i-1;j++){
			soma = soma + A.at(i).at(j)*x.at(j);
		}
		x.at(i) = (B.at(i) - soma);
	}
	return x;
}

std::vector<double> LU_piv_parc(int n, std::vector<std::vector<double>> A ,std::vector<double> B);
std::vector<double> LU_piv_parc(int n, std::vector<std::vector<double>> A ,std::vector<double> B){	
	std::vector<double> p, blin, x, y;
	blin.push_back(0);
	blin.push_back(0);
	blin.push_back(0);
	double m = 0;
	double* pv;
	pv = new double[2];
	for(int i=0; i<n;i++){
		p.push_back(i);
	}
	for(int k=0; k<n-1;k++){
		pv = pivo(A, k, n);
		if (pv[0] == 0){
			break;
		}
		if(pv[1] != k){
			A = permuta(p, A, k, pv[1], n);
		}
		for(int i=k+1; i<n;i++){
			m = A.at(i).at(k)/A.at(k).at(k);
			A.at(i).at(k) = m;
			for (int j=k+1;j<n;j++){
				A.at(i).at(j) = A.at(i).at(j) - m*A.at(k).at(j);
			}

		}
		for(int i = 0;i<n;i++){
			pv[1] = p.at(i);
			blin.at(i) = B.at(pv[1]);
		}
		y = subst_sucess_mod(n, A, blin);
		x = sub_ret(n, A, y);
	}
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
	std::vector<double> x = LU_piv_parc(3,A,B);

	std::cout <<"x = [ "<< x.at(0) << " "<< x.at(1) << " "<< x.at(2) << " ]\n";

}



