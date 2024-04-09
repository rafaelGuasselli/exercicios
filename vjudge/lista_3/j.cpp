#include <iostream>
#include <bits/stdc++.h>

//AXY = (Y+X)
//ABX = 2X

using namespace std;
long long possibilidades;

string buscar(string treinoAtual, long long atual, long long anterior) {
	if (atual == possibilidades) {
		return treinoAtual;
	} else if (anterior*2 > possibilidades) {
		return "";
	}

	string resultadoA = buscar("A", atual+anterior, atual);
	string resultadoB = buscar("AB", 2*atual, atual);

	if (resultadoA.size() > 0 && resultadoB.size() > 0) {
		if (resultadoB.compare(resultadoA) < 0) {
			return resultadoB + treinoAtual;
		} else {
			return resultadoA + treinoAtual;
		}
	}

	if (resultadoA.size() > 0) {
		return resultadoA + treinoAtual;
	}

	if (resultadoB.size() > 0) {
		return resultadoB + treinoAtual;
	}

	return "";
}

int main() {	
	cin>>possibilidades;
	string resultado = buscar("AB", 2, 1);
	if (resultado.size() > 0) {
		cout<<resultado<<endl;
	} else {
		cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}