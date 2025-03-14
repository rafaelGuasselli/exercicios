#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Domino{
	int esquerda = -1;
	int direita = -1;
};

int qtdEspacos, qtdPecas; 
Domino pecas[16];
int resultado[16] = {0};
bool usado[16] = {false};

void inverter(Domino &peca) {
	int aux = peca.esquerda;
	peca.esquerda = peca.direita;
	peca.direita = aux;
}

bool resolver(int indice) {
	if (indice == qtdEspacos+1){
		return pecas[resultado[indice-1]].direita == pecas[resultado[indice]].esquerda;
	}

	for (int i = 1; i < qtdPecas+1; i++) {
		if (usado[i]) continue;
		if (pecas[resultado[indice-1]].direita == pecas[i].esquerda) {
			resultado[indice] = i;
			usado[i] = true;

			if(resolver(indice+1)){
				return true;
			}

			usado[i] = false;
			resultado[indice] = -1;
		} 

		inverter(pecas[i]);

		if (pecas[resultado[indice-1]].direita == pecas[i].esquerda) {
			resultado[indice] = i;
			usado[i] = true;
			if(resolver(indice+1)){
				return true;
			}
			usado[i] = false;
			resultado[indice] = -1;
		} 
	}

	return false;
}

int main() {
	while(true){
		cin>>qtdEspacos;
		if (qtdEspacos == 0) {
			break;
		}

		for(int i = 0; i < 16; i++) {
			usado[i] = false;
			resultado[i] = 0;
			pecas[i].direita = -1;
			pecas[i].esquerda = -1;	
		}

		cin>>qtdPecas;

		usado[0] = true;
		resultado[0] = 0;
		usado[qtdPecas+1] = true;
		resultado[qtdEspacos+1] = qtdPecas+1;
		
		cin>>pecas[0].esquerda;
		cin>>pecas[0].direita;
		cin>>pecas[qtdPecas+1].esquerda;
		cin>>pecas[qtdPecas+1].direita;

		for (int i = 1; i < qtdPecas+1; i++) {
			cin>>pecas[i].esquerda;
			cin>>pecas[i].direita;
		}

		if(resolver(1)){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}