#include <iostream>
#include <cmath>
#include <vector>


std::vector<double> gauss_jordan(int n, std::vector<std::vector<double>> A ,std::vector<double> B);
std::vector<double> gauss_jordan(int n, std::vector<std::vector<double>> A ,std::vector<double> B){
	for(int k=0; k<n;k++){
		for(int j = k+1;j<n;j++){
			A.at(k).at(j) = A.at(k).at(j)/A.at(k).at(k);
		}
		B.at(k) = B.at(k)/A.at(k).at(k);
		A.at(k).at(k) = 1;
		for(int i=0;i<n;i++){
			if(i != k){
				for(int j=k+1;j<n;j++){
					A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k)*A.at(k).at(j);
				}
				B.at(i) = B.at(i) - A.at(i).at(k)*B.at(k);
				A.at(i).at(k) = 0;
			}
		}
	}

	return B;
}

double gauss_jordan_DET(int n, std::vector<std::vector<double>> A);
double gauss_jordan_DET(int n, std::vector<std::vector<double>> A){
	std::vector<double> x;
	double det=1;
	for(int k=0; k<n;k++){
		for(int j = k+1;j<n;j++){
			A.at(k).at(j) = A.at(k).at(j)/A.at(k).at(k);
		}
		//A.at(k).at(k) = 1;
		for(int i=0;i<n;i++){
			if(i != k){
				for(int j=k+1;j<n;j++){
					A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k)*A.at(k).at(j);
				}
				A.at(i).at(k) = 0;
			}
		}
	}
	for(int j = 0;j<n;j++){
		det = det*A.at(j).at(j);
	}

	return det;
}

std::vector<std::vector<double>> gauss_jordan_MI(int n, std::vector<std::vector<double>> A);
std::vector<std::vector<double>> gauss_jordan_MI(int n, std::vector<std::vector<double>> A){
	std::vector<std::vector<double>> AI = A;
	for(int l=0;l<n;l++){
		for(int m=0;m<n;m++){
			if(m == l){
				AI.at(l).at(m) = 1;
			} else{
				AI.at(l).at(m) = 0;
			}	
		}
	}
	for(int k=0; k<n;k++){
		for(int j = k+1;j<n;j++){
			AI.at(k).at(j) = AI.at(k).at(j)/A.at(k).at(k);
			A.at(k).at(j) = A.at(k).at(j)/A.at(k).at(k);
		}
		for (int c=0;c<k;c++){
			AI.at(k).at(c) = AI.at(k).at(c)/A.at(k).at(k);
		}
		AI.at(k).at(k) = AI.at(k).at(k)/A.at(k).at(k);
		A.at(k).at(k) = 1;
		for(int i=0;i<n;i++){
			if(i != k){
				for(int j=k+1;j<n;j++){
					A.at(i).at(j) = A.at(i).at(j) - A.at(i).at(k)*A.at(k).at(j);
					AI.at(i).at(j) = AI.at(i).at(j) - AI.at(i).at(k)*A.at(k).at(j);
				}
				for(int j=k-1;j>=0;j--){
					AI.at(i).at(j) = AI.at(i).at(j) - A.at(i).at(k)*AI.at(k).at(j);
				}
				AI.at(i).at(k) = - A.at(i).at(k)*AI.at(k).at(k);
				A.at(i).at(k) = 0;
			}
		}
	}


	return AI;
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
	
	std::vector<double> x = gauss_jordan(3,A,B);
	
	double det = gauss_jordan_DET(3,A);
	
	std::vector<std::vector<double>> AI = gauss_jordan_MI(3,A);
	
	std::cout <<"x = [ "<< x.at(0) << " "<< x.at(1) << " "<< x.at(2) << " ]\n\n";

	std::cout <<"Matriz Inversa\n"<< AI.at(0).at(0) << " "<< AI.at(0).at(1) << " "<< AI.at(0).at(2) << "\n"<< AI.at(1).at(0) << " "<< AI.at(1).at(1) << " "<< AI.at(1).at(2) << "\n"<< AI.at(2).at(0) << " "<< AI.at(2).at(1) << " "<< AI.at(2).at(2) << "\n\n";


	//No determinante não precisamos do B, logo, podemos remover
	std::cout <<"Determinante = "<< det << "\n";

}
