#include <bits/stdc++.h> 

using namespace std;

int main() {	
	while (true) {
		int qtdNum; cin>>qtdNum;
		if (qtdNum == 0) {
			break;
		}

		int numeros[1000];
		for (int i = 0; i < qtdNum; i++) {
			cin>>numeros[i];
		}

		int fim = 0;
		int soma = 0;
		int inicio = 0;
		
		int maiorFim = 0;
		int maiorSoma = 0;
		int maiorInicio = 0;		
		int menorTamanho = 0;

		for (int i = 0; i < qtdNum; i++) {
			soma += numeros[i];

			if (soma <= 0) {
				inicio = i + 1;
				soma = 0;
			}

			if (soma > maiorSoma) {
				maiorFim = i + 1;
				maiorSoma = soma;
				maiorInicio = inicio;
				menorTamanho = i - inicio;
			} else if (soma == maiorSoma && (i - inicio) < menorTamanho){
				maiorFim = i + 1;
				maiorSoma = soma;
				maiorInicio = inicio;
				menorTamanho = i - inicio;
			}
		}

		for (int i = maiorInicio; i < maiorFim; i++) {
			if (numeros[i] == 0) {
				continue;
			}

			if (i > maiorInicio) {
				cout<<" ";
			} 

			cout<<numeros[i];
		}

		if (maiorFim - maiorInicio == 0) {
			cout<<"0";
		}

		cout<<endl;
	}

	return 0;
}