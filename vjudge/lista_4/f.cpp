#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {	
    int qtdTestes; cin>>qtdTestes;

    int count = 1;
    for (int t = 0; t < qtdTestes; t++) {
        int qtdDegraus; cin>>qtdDegraus;
        int anterior = 0;
        vector<ll> diferencas;
		ll maior = 0;

        for (int i = 0; i < qtdDegraus; i++) {
            ll atual; cin>>atual;
            diferencas.push_back(atual-anterior);

			if (atual-anterior > maior) {
				maior = atual-anterior;
			}

            anterior = atual;
        }

        ll solucao = maior;
		ll atual = maior;

        for (auto difIt = diferencas.begin(); difIt != diferencas.end(); difIt++) {
			ll difAtual = *difIt;
			if (difAtual > atual) {
				solucao++;
				break;
			}

			if (difAtual == atual) {
				atual--;
			}
        }

        cout<<"Case "<<count<<": "<<solucao<<endl;
        count++;
    }

    return 0;
}