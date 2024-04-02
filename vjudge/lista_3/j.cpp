#include <iostream>
#include <bits/stdc++.h>

//ABX = (B+X)
//ABBX = 2X


using namespace std;
long long possibilidades;

string buscar(string atual, long long posAtual, long long anterior, long long anteAnterior) {
	if (posAtual == possibilidades) {
		return atual;
	} else if (anterior*2 > possibilidades) {
		return "";
	}


	if (atual == "A") {
		string resultadoA = buscar("A", posAtual+anterior, posAtual, anterior);
		string resultadoB = buscar("B", posAtual, posAtual, anterior);
		
		if (resultadoA.size() > 0 && resultadoB.size() > 0) {
			if (resultadoB.compare(resultadoA) < 0) {
				return resultadoB + atual;
			} else {
				return resultadoA + atual;
			}
		}

		if (resultadoA.size() > 0) {
			return resultadoA + atual;
		}

		if (resultadoB.size() > 0) {
			return resultadoB + atual;
		}
	} else {
		string resultadoA = buscar("A", posAtual+anterior, posAtual, anterior);
		if (resultadoA.size() > 0) {
			return resultadoA + atual;
		}
	}

	return "";
}

int main() {	
	cin>>possibilidades;
	string resultado = buscar("B", 1, 1, 1);
	if (resultado.size() > 0) {
		cout<<resultado<<endl;
	} else {
		cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}