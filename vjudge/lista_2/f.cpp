#include <bits/stdc++.h>
#define TAMANHO_MAXIMO 1000000

using namespace std;


int main() {
	while(true){
		int qtdIntervalos, qtdRepetidos; cin>>qtdIntervalos>>qtdRepetidos;
		if (qtdIntervalos == qtdRepetidos && qtdRepetidos == 0) {
			break;
		}


		bitset<1000010> agenda;
		bool conflito = false;
		for (int i = 0; i < qtdIntervalos; i++) {
			int inicio, fim; cin>>inicio>>fim;

			for (int j = inicio; j < fim && j <= TAMANHO_MAXIMO; j++) {
				if (agenda.test(j)) {
					conflito = true;
					break;
				}

				agenda.set(j);
			}
		}

		for (int i = 0; i < qtdRepetidos; i++) {
			int inicio, fim, intervalo; cin>>inicio>>fim>>intervalo;

			while (inicio <= TAMANHO_MAXIMO) {
				for (int j = inicio; j < fim && j <= TAMANHO_MAXIMO; j++) {
					if (agenda.test(j)) {
						conflito = true;
						break;
					}

					agenda.set(j);
				}

				inicio += intervalo;
				fim += intervalo;
			}
		}

		if (conflito) {
			cout<<"CONFLICT"<<endl;
		} else {
			cout<<"NO CONFLICT"<<endl;
		}
	}

    return 0;
}