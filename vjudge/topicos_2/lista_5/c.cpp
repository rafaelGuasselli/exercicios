#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> intervalos;

signed main() {	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while (true) {
		int tamanhoRua, qtdPostos; cin>>tamanhoRua>>qtdPostos;
		int remover = 0;

		if (tamanhoRua == 0 && qtdPostos == 0) {
			break;
		}

		intervalos.clear();
		intervalos.push_back({0, 0});
		for (int i = 0; i < qtdPostos; i++) {
			int pos, raio; cin>>pos>>raio;
			int esquerda = pos - raio;
			int direita = pos + raio;
			intervalos.push_back({esquerda, direita});
		}
		intervalos.push_back({tamanhoRua, tamanhoRua});

		sort(intervalos.begin(), intervalos.end());
		int qtdRemover = 0;
		pair<int, int>* anterior = &intervalos[0];
		pair<int, int>* atual = &intervalos[1];
		pair<int, int>* proximo = &intervalos[2];

		for (int i = 3; i < qtdPostos+2; i++) {
			if (anterior->second < atual->first) {
				qtdRemover = -1;
				break;
			}

			if (anterior->second >= proximo->first) {
				qtdRemover++;
				atual = atual->second > proximo->second ? atual : proximo;
				proximo = &intervalos[i];
			} else if (atual->second < proximo->first) {
				qtdRemover = -1;
				break;
			} else {
				anterior = atual;
				atual = proximo;
				proximo = &intervalos[i];
			}
		}

		cout<<qtdRemover<<endl;
	}



	return 0;
}