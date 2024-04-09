	#include <bits/stdc++.h>
	typedef long double ll;

	using namespace std;
	int valores[4] = {2, 3, 5, 7};
	ll limites[3] = {100, 9900, 990000};

	ll acharWatts(ll soma) {
		ll watts = 0;
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				watts += soma/valores[i];
				break;
			}

			watts += min(soma, limites[i]*valores[i])/valores[i];
			soma -= min(soma, limites[i]*valores[i]);
		}

		return watts;
	}

	ll calcularPreco(ll watts) {
		ll preco = 0;
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				preco += watts * valores[i];
				break;
			}

			preco += min(watts, limites[i]) * valores[i];
			watts -= min(watts, limites[i]);
		}

		return round(preco);
	}

	#define precisao 1000000
	ll buscar(ll watts, ll diferenca){
		ll inicio = 0;
		ll fim = watts/2;
		ll meio = 0;

		while (inicio < fim && round((fim-inicio)/2 * precisao) > 0) {
			meio = inicio + (fim-inicio)/2;
			ll precoA = calcularPreco(meio);
			ll precoB = calcularPreco(watts-meio);
			ll dif = precoB - precoA;

			if (dif == diferenca) {
				return precoA;
			} else if (dif < diferenca) {
				fim = meio;
			} else{
				inicio = meio;
			}
		}

		return calcularPreco(meio);
	}

	int main() {
		while (true) {
			ll soma, diferenca; cin>>soma>>diferenca;

			if (soma == 0 && diferenca == 0) {
				break;
			}

			ll watts = acharWatts(soma);
			ll preco = round(buscar(watts, diferenca));
			cout<<(long long)preco<<endl;
		}

		return 0;
	}