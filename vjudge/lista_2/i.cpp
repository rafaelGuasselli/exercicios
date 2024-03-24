#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
	while(true) {
		int qtdAlunos; cin>>qtdAlunos;
		if (qtdAlunos == 0) {
			break;
		}

		map<set<int>, set<int>> combinacoes;
		for (int i = 0; i < qtdAlunos; i++) {
			set<int> combinacao;
			for (int j = 0; j < 5; j++) {
				int materia; cin>>materia;
				combinacao.insert(materia);
			}

			combinacoes[combinacao].insert(i);
		}

		int maior = 0;
		set<int> alunosFazendo;
		for (auto combinacao: combinacoes) {
			int proximo = combinacao.second.size();
			if (proximo > maior) {
				alunosFazendo.clear();
				maior = proximo;
			}
			
			if (proximo == maior) {
				alunosFazendo.insert(combinacao.second.begin(), combinacao.second.end());
			}
		}

		cout<<alunosFazendo.size()<<endl;
	}

	return 0;
}