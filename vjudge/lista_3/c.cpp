#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int qtdTestes; cin>>qtdTestes;
	for (int i = 0; i < qtdTestes; i++) {
		int objetivo; cin>>objetivo;
		int qtdBarras; cin>>qtdBarras;

		set<int> somas;
		somas.insert(0);
		for (int j = 0; j < qtdBarras; j++) {
			int barra; cin>>barra;
			set<int> novasSomas;

			for (int numero: somas) {
				if (barra+numero > objetivo) {
					break;
				}

				novasSomas.insert(barra+numero);
			}

			somas.insert(novasSomas.begin(), novasSomas.end());
		}

		if (somas.find(objetivo) != somas.end()) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}