#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long possibilidades;
string treino;
bool achouUm = false;

void buscar(string atual, string concatenado, long anterior, long anteAnterior) {
	long posAtual;
	if (atual == "A") {
		posAtual = anteAnterior+anterior;
	} else {
		posAtual = anterior;
	}

	if (posAtual == possibilidades) {
		if ((atual+concatenado).compare(treino) < 0) {
			treino = atual+concatenado;
		}

		if (!achouUm) {
			treino = atual+concatenado;
		}
		achouUm = true;
	} 
	
	if (posAtual >= possibilidades) {
		return;
	}

	if (atual == "A") {
		buscar("A", atual+concatenado, posAtual, anterior);
		buscar("B", atual+concatenado, posAtual, anterior);
	} else {
		buscar("A", atual+concatenado, posAtual, anterior);
	}
}

int main() {	
	cin>>possibilidades;

	buscar("B", "", 1, 1);
	if (achouUm) {
		cout<<treino<<endl;
	} else {
		cout<<"IMPOSSIBLE"<<endl;
	}

	return 0;
}