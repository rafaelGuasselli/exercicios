#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int tamanhoFita, qtdCds;
int cds[20] = {0};

int main() {
	while(cin>>tamanhoFita>>qtdCds) {
		for (int i = 0; i < qtdCds; i++) {
			cin>>cds[i];
		}

		int limite = 1<<qtdCds;
		int atual = 0;
		int soma = 0;
		int maisProximo = 0;
		int maisProximoSoma = 0;

		while(atual<limite){
			soma = 0;
			for (int i = 0; i < qtdCds; i++) {
				if (atual&1<<i) {
					soma += cds[i];
				}
			}

			
			if ((tamanhoFita-soma) >= 0 && (tamanhoFita-soma) < (tamanhoFita-maisProximoSoma)) {
				maisProximo = atual;
				maisProximoSoma = soma;
			}

			if (soma == tamanhoFita) {
				break;
			}

			atual++;
		}

		for(int i = 0; i < qtdCds; i++) {
			if (1<<i & maisProximo) {
				cout<<cds[i]<<" ";
			}
		}

		cout<<"sum:"<<maisProximoSoma<<endl;
	}

	return 0;
}