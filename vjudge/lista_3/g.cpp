#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int objetivo, qtdNumeros;

int main() {	
	while (true) {
		cin>>objetivo>>qtdNumeros;

		if (objetivo == 0 && qtdNumeros == 0) {
			break;
		}

		map<int, set<vector<int>, greater<vector<int>>>> conjuntos;
		set<int> somas;
		somas.insert(0);
		for (int i = 0; i < qtdNumeros; i++) {
			int novoNum; cin>>novoNum;
			set<int> novasSomas;
			map<int, set<vector<int>, greater<vector<int>>>> novosConjuntos;

			for (int numero: somas) {
				if (novoNum+numero > objetivo) {
					break;
				}

				novasSomas.insert(novoNum+numero);
				for (vector<int> conjunto:conjuntos[numero]) {
					vector<int> novoConjunto(conjunto);
					novoConjunto.push_back(novoNum);
					novosConjuntos[novoNum+numero].insert(novoConjunto);
				}

				if (conjuntos[numero].size() == 0) {
					vector<int> novoConjunto;
					novoConjunto.push_back(novoNum);
					novosConjuntos[novoNum+numero].insert(novoConjunto);
				}
			}

			somas.insert(novasSomas.begin(), novasSomas.end());
			for (auto item:novosConjuntos) {
				for(auto elemento:item.second) {	
					conjuntos[item.first].insert(elemento);
				}
			}

			conjuntos.insert(novosConjuntos.begin(), novosConjuntos.end());
		}	

		cout<<"Sums of "<<objetivo<<":"<<endl;
		if (conjuntos[objetivo].size() == 0) {
			cout<<"NONE"<<endl;
		} else {
			for (auto numeros: conjuntos[objetivo]) {
				for(auto it = numeros.begin(); it != numeros.end(); it++) {
					if(it != numeros.begin()) cout<<"+";
					cout<<*it;
				}
				cout<<endl;
			}
		}
	}

	return 0;
}