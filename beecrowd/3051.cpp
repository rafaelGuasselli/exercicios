#include <bits/stdc++.h>

using namespace std;

queue<int> copy_queue(queue<int> &Q) {    
    queue<int>Q2 = Q; 
    return Q2;
}

int main(){
	int qtdNumeros, objetivo; cin>>qtdNumeros>>objetivo;
	int qtdQuadrados = 0;
	int soma = 0;

	vector<int> numeros;
	queue<int> fila;

	for (int i = 0; i < qtdNumeros; i++) {
		int atual; cin>>atual;
		numeros.push_back(atual);
	} 

	for (int numero:numeros) {
		soma += numero;
		if (soma == objetivo) {
			qtdQuadrados++;
		}

		while (soma > objetivo) {
			soma -= fila.front(); fila.pop();
			if (soma == objetivo) {
				qtdQuadrados++;
			}
		}

		fila.push(numero);
	}

	numeros.reserve(numeros.size());
	while (fila.size() > 0) {
		fila.pop();
	}

	for (int numero:numeros) {
		soma += numero;
		if (soma == objetivo) {
			qtdQuadrados++;
		}

		while (soma > objetivo) {
			soma -= fila.front(); fila.pop();
			if (soma == objetivo) {
				qtdQuadrados++;
			}
		}

		fila.push(numero);
	}

	cout<<qtdQuadrados<<endl;

	return 0;
}