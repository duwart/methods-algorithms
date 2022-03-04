#include <iostream>
#include <cmath>

float funcao(float a){
	return 2*cos(a) - exp(a)/2;
}

float funcaoDerivada(float a){
	return -2*sin(a) + exp(a)*(-1/2);
}

float newton_rapson(float x, float prec1, float prec2){
	if (fabs(funcao(x)) < prec1){
		return x;
	}
	int k=1;
	float x1 = x - funcao(x)/funcaoDerivada(x);
	while(!(fabs(funcao(x1)) < prec1 || fabs(x1-x)< prec2)){
		x = x1;
		k=k+1;
		x1 = x - funcao(x)/funcaoDerivada(x);
	}
	return x;
}


float secante(float a, float b, float prec1, float prec2){
	
	if (fabs(funcao(a)) < prec1 || fabs(b - a) < prec2){
		return a;
	}
	int k=1;
	float x;
	x = b - (funcao(b)/(funcao(b)-funcao(a)))*(b-a);
	while(!(fabs(funcao(x))<prec1 || fabs(x-b)<prec2)){
		a = b;
		b = x;
		k=k+1;
		x = b - (funcao(b)/(funcao(b)-funcao(a)))*(b-a);
	}
	return x;
}



int main(){

	std::cout << "\nMetodo da Newton-Rapson: " << newton_rapson(1,0.0001,0.0001) <<"\n";
	std::cout << "Metodo da Secante: " << secante(0.5,1,0.0001,0.0001) << "\n";

}
