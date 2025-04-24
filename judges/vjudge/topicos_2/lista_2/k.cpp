#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int contadorCase = 1;
	while(true) {
		int qtdNumeros; cin>>qtdNumeros;
		if (qtdNumeros == 0) {
			break;
		}

		set<int> numeros;
		for (int i = 0; i < qtdNumeros; i++) {
			int numero; cin>>numero;
			numeros.insert(numero);
		}


		set<int> somas;
		for (auto it = numeros.begin(); it != numeros.end(); it) {
			int numeroA = *it;
			for (auto itb = ++it; itb != numeros.end(); ++itb) {
				somas.insert(numeroA+(*itb));
			}
		}


		int qtdQueries; cin>>qtdQueries;
		cout<<"Case "<<contadorCase<<":"<<endl;
		for (int i = 0; i < qtdQueries; i++) {
			int query; cin>>query;

			auto lowerB = somas.lower_bound(query);
			int closestSum = *lowerB;

			if (lowerB != somas.begin()) {
				auto evenLowerB = *(--lowerB);
				if (abs(evenLowerB-query)<abs(closestSum-query)) {
					closestSum = evenLowerB;
				}
			}

			cout<<"Closest sum to "<<query<<" is "<<closestSum<<"."<<endl;
		}
		
		contadorCase++;
	}

	return 0;
}