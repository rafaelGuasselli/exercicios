#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {	
	while (true) {
		int qtdEntregas, limiteHoraExtra, taxaHoraExtra;
		cin>>qtdEntregas>>limiteHoraExtra>>taxaHoraExtra;
		if (qtdEntregas == 0 && limiteHoraExtra == 0 && taxaHoraExtra == 0) {
			break;
		}

		multiset<int, greater<int>> manha;
		multiset<int> noite;

		for (int i = 0; i < qtdEntregas; i++) {
			int m, n; cin>>m>>n;
			manha.insert(m);
			noite.insert(n);
		}

		ll extra = 0;
		for (int manhaAtual: manha) {
			auto noiteIt1 = noite.lower_bound(limiteHoraExtra-manhaAtual);
			if (noiteIt1 == noite.end()) {
				noiteIt1 = prev(noiteIt1, 1);
			} 

			auto noiteIt2 = noiteIt1;
			if (noiteIt1 != noite.begin()) {
				noiteIt2 = prev(noiteIt1, 1);
			} 

			int noiteAtual1 = *noiteIt1;
			int noiteAtual2 = *noiteIt2;
			int extra1 = abs(noiteAtual1 + manhaAtual - limiteHoraExtra);
			int extra2 = abs(noiteAtual2 + manhaAtual - limiteHoraExtra);
			if (extra1 <= extra2) {
				extra += max(0, (noiteAtual1 + manhaAtual) - limiteHoraExtra);
				noite.erase(noiteIt1);
			} else {
				extra += max(0, (noiteAtual2 + manhaAtual) - limiteHoraExtra);
				noite.erase(noiteIt2);	
			}
		}

		cout<<extra*taxaHoraExtra<<endl;
	}

	return 0;
}