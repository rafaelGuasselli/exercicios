#include <bits/stdc++.h>
using namespace std;
#define num int

vector<pair<num, num>> intervalos;

int main() {	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while (true) {
		num tamanhoRua, qtdPostos; cin>>tamanhoRua>>qtdPostos;
		num remover = 0;

		if (tamanhoRua == 0 && qtdPostos == 0) {
			break;
		}

		for (num i = 0; i < qtdPostos; i++) {
			num pos, raio; cin>>pos>>raio;
			num esquerda = max(0, pos - raio);
			num direita = min(tamanhoRua, pos + raio);
			intervalos.push_back(make_pair(esquerda, direita));
		}

		sort(intervalos.begin(), intervalos.end());

		bool impossivel = false;
		int ultimoPos = 0;
		for (num i = 0; i < qtdPostos; i++) {
			auto intervalo = intervalos[i];

			cout<<ultimoPos<<" "<<intervalo.first<<endl;
			if (intervalo.first > ultimoPos) {
				impossivel = true;
				break;
			}
			
			ultimoPos = intervalo.second;
		}

		if (ultimoPos < tamanhoRua) {
			impossivel = true;
		}
		
		for (num i = 0; i < qtdPostos && !impossivel; i++) {
			num esquerda = intervalos[i].first;
			num direita = intervalos[i].second;

			for (num j = i+1; j < intervalos.size(); j++) {
				auto intervalo = intervalos[i];
				if (esquerda >= intervalo.first && direita <= intervalo.second) {
					remover++;
				}
			}

		}



		if (impossivel) {
			cout<<"-1"<<endl;
		} else {
			cout<<ultimoPos<<endl;
		}

	}

	return 0;
}