#include <iostream>
#include <cmath>

float funcao(float a){
	return pow(a,3) - 9*a + 3;
}

float phi(float a){
	return (-pow(a,3)-3)/(-9);
}

float polinomio(float x, int itmax, float prec1, float prec2){
	float a[4] = {3, 9, 0, 1};
	float deltax = x;
	float b = 0;
	float c = 0;
	for(int k=0; k<itmax;k++){
		b = a[3];
		c = b + c*x;
		for(int i=2;i>0;i--){
			b = a[i] + b*x;
			c = b + c*x;
		}
		b = a[0] + b*x;
		if (fabs(b) <= prec1){
			return x;
		}
		deltax = b/c;

		x = x - deltax;
		if (fabs(deltax) <= prec2){
			return x;
		}
	}
	return x;
}

float ponto_fixo(float x0, float prec1, float prec2){
	if(fabs(funcao(x0))<prec1){
		return x0;
	}
	int k = 1;
	float x = phi(x0);
	while (!(fabs(funcao(x))<prec1 || fabs(x - x0)<prec2)){
		x0 = x;
		k=k+1;
		x = phi(x0);
	}
	return x;
}


int main(){

	std::cout << "\nMetodo do ponto fixo: "<< ponto_fixo(0.5,0.0001,0.0001) << "\n";
	std::cout << "Metodo do Polinomio: "<< polinomio(0.5,20,0.0001,0.0001) << "\n";

}



