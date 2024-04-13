#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {	
	int qtdTestes; cin>>qtdTestes;
	
	for (int i = 0; i < qtdTestes; i++) {
		int qtdMoedas; cin>>qtdMoedas;
		ll moedas[1000];
		for (int j = 0; j < qtdMoedas; j++) {
			cin >> moedas[j];
		}

		sort(moedas, moedas+qtdMoedas);

		int soma = 0;
		int qtd = 0;
		for (int j = 0; j < qtdMoedas; j++) {
			if (soma < moedas[j]) {
				soma += moedas[j];
				qtd++;
			} else {
				soma -= moedas[j-1];
				qtd--;
				j--;
			}
		}

		cout<<qtd<<endl;
	}

	return 0;
}