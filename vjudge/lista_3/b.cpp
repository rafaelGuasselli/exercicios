#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Restricao{
	int a, b, distancia;
};

int main() {
	while (true) {
		int qtdAdolescentes, qtdRestricoes; cin>>qtdAdolescentes>>qtdRestricoes;
		int permutacaoAtual[qtdAdolescentes];
		vector<Restricao> restricoes;

		if (qtdAdolescentes == 0 & qtdRestricoes == 0) {
			break;
		}

		for (int i = 0; i < qtdAdolescentes; i++) {
			permutacaoAtual[i] = i;
		}

		for (int i = 0; i < qtdRestricoes; i++) {
			int a, b, distancia; cin>>a>>b>>distancia;
			restricoes.push_back({a, b, distancia});
		}

		int possibilidades = 0;

		do{
			bool falha = false;
			for (Restricao restricao: restricoes) {
				int indexA = permutacaoAtual[restricao.a];
				int indexB = permutacaoAtual[restricao.b];
				
				if (restricao.distancia < 0) {
					if (abs(indexA-indexB) < abs(restricao.distancia)) {
						falha = true;
						break;	
					}
				} else {
					if (abs(indexA-indexB) > abs(restricao.distancia)) {
						falha = true;
						break;
					}
				}
			} 

			if (!falha) {
				possibilidades++;
			}
		} while(next_permutation(permutacaoAtual, permutacaoAtual+qtdAdolescentes));

		cout<<possibilidades<<endl;
	}
	return 0;
}