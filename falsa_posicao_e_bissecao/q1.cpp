#include <iostream>
#include <cmath>


float funcao(float a){
	return 2*cos(a) - exp(a)/2;
}

float falsa_posicao(float a, float b, float prec1, float prec2){
	if (b-a<prec1){
		if(fabs(funcao(a))<prec2 || fabs(funcao(b))<prec2){
			return a;
		}
	}
	float M = funcao(a);
	float x;
	int i = 1;
	while((b-a)>prec1){
		x = (a*funcao(b) - b*funcao(a))/(funcao(b)-funcao(a));
		
		i = i+1;
		if(fabs(funcao(x)) <= prec2){
			return x;
		}
		if(M*funcao(x) > 0){
			a = x;
		} else{
			b = x;
		}
	}
	i = i+1;
	return (a+b)/2;
}

float bissecao(float a, float b, float prec){
	int i = 1;
	if(b-a < prec){
		
		return (b+a)/2;
	}
	float M = funcao(a);
	float x;
	while((b-a)>prec){
	
		i = i+1;
		x = (a + b)/2;
		if(M*funcao(x) > 0){
			a = x;
		} else{
			b = x;
		}
	}
	return (a + b)/2;
}

int main(){

	std::cout << "\nMetodo da bissecao: " << bissecao(M_PI/4,M_PI/2, 0.0001) << "\n";
	std::cout << "Metodo da falsa posicao: " << falsa_posicao(M_PI/4,M_PI/2, 0.0001, 0.0001)<< "\n";

}

