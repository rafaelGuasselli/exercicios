#include <bits/stdc++.h>
#include <math.h>

using namespace std;


int somaSequencias(int x, int y, int mod){
	if (x == y) {
		return 0;
	}

	int menor = min(x, y);
	int maior = max(x, y);

	int tamanhoDoRange = ((maior - menor + 1)/2) % mod;
	return ((menor + maior) * tamanhoDoRange) % mod;

}


int main(){
	while (true) {
		double primeiraCaixa, ultimaCaixa, qtdCaminhoes; cin>>primeiraCaixa>>ultimaCaixa>>qtdCaminhoes;
		if (primeiraCaixa == ultimaCaixa && ultimaCaixa == qtdCaminhoes && qtdCaminhoes == 0) {
			break;
		}

		set<int> caminhoes;
		for (int i = 0; i < qtdCaminhoes; i++) {
			int novoCaminhao; cin>>novoCaminhao;
			bool add = true;

			for (auto caminhao : caminhoes) {
				if (novoCaminhao % caminhao == 0) {
					add = false;
					break;
				}
			}

			if (add) {
				caminhoes.insert(novoCaminhao);
			}
		}

		int total = 0;
		for (auto caminhao : caminhoes) {
			if (caminhao == 1) {
				total += somaSequencias(primeiraCaixa, ultimaCaixa, 1300031);
				break;
			} 

			double primeiroElemento = ceil(primeiraCaixa/caminhao)*caminhao;
			double n = floor(ultimaCaixa/caminhao);

			int soma = ((int)(n/2 * (primeiroElemento*2 + (n-1)*caminhao))) % 1300031;

			total = (total + soma) % 1300031;
		}

		set<int> combinacoes;
		for (auto it = caminhoes.begin(); it != --caminhoes.end(); it) {
			int caminhaoA = *it;
			for (auto itb = ++it; itb != caminhoes.end(); ++itb) {
				bool add = true;
				for (auto caminhao : combinacoes) {
					if (caminhaoA*(*itb) % caminhao == 0) {
						add = false;
						break;
					}
				}

				if (add) combinacoes.insert(caminhaoA*(*itb));
			}
		}

		for (auto caminhao : combinacoes) {
			if (caminhao == 1) {
				total += somaSequencias(primeiraCaixa, ultimaCaixa, 1300031);
				break;
			} 

			double primeiroElemento = ceil(primeiraCaixa/caminhao)*caminhao;
			double n = floor(ultimaCaixa/caminhao);

			int soma = ((int)(n/2 * (primeiroElemento*2 + (n-1)*caminhao))) % 1300031;

			total = (total - soma) % 1300031;
		}


		cout<<total<<endl;

	}

    return 0;
}