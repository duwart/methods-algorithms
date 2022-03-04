#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>

using std::string;


// CONVERSOR BINÁRIO PARA DECIMAL 1
int bindec1(string numbin){
	int b = -1;
	int b_novo;
	for (int i = 0; i < numbin.size(); i++){
		if(b == -1){
			b = int(numbin[i]-48);
		} else {
			b_novo = 2*b+int(numbin[i]-48);
			b = b_novo;
		}
	}
	return b;
}


// CONVERSOR BINÁRIO PARA DECIMAL 2
int bindec2(string numbin){
	int b_novo = 0;
	for (int i = 0; i < numbin.size(); i++){
		b_novo += b_novo + (pow(2, i))*int(numbin[i]-48);
	}
	return b_novo;
}


// CONVERSOR DECIMAL PARA BINÁRIO
string decbin(int numdec){
	int d = numdec;

	if (d==1){
		return "1";
	} else if (d==0) {
		return "0";
	} else{
		return decbin(d/2)+(d%2 == 0 ? "0" : "1");
	}
}


// FUNÇÃO MAIN

int main(){
	string numbin;
	int numdec = 0;
	int res = 999;
	
	std::cout << "\nBinario -> Decimal, digite 0\nDecimal -> Binario, digite 1\nQual conversao deseja fazer? ";
	std::cin >> res;
	if(res == 0){
		std::cout << "\nDigite um valor inteiro em binario: ";
		std::cin >> numbin;
		//bindec1(numbin);
		std::cout << bindec2(numbin);
	} else if(res == 1){
		std::cout << "\nDigite um valor inteiro em decimal: ";
		std::cin >> numdec;
		std::cout << decbin(numdec);
	} else {
		std::cout << "\nValor Invalido!\n";
	}
	
	return 0;
}