#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int qtdDias; cin>>qtdDias;
		if (qtdDias == 0) {
			break;
		}

		long total = 0;
		multiset<int> notas;
		for (int i = 0; i < qtdDias; i++) {
			int qtdNotas; cin>>qtdNotas;

			for (int j = 0; j < qtdNotas; j++) {
				int nota; cin>>nota;
				notas.insert(nota);
			}

			int menor = *notas.begin();
			int maior = *(--notas.end());

			total += abs(maior - menor);
			
			notas.erase(notas.begin());
			notas.erase(--notas.end());
		}

		cout<<total<<endl;
	}

	return 0;
}