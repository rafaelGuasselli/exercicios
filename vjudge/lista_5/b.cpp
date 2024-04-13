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

		multiset<int> manha;
		multiset<int> noite;

		for (int i = 0; i < qtdEntregas; i++) {
			int m, n; cin>>m>>n;
			manha.insert(m);
			noite.insert(n);
		}

		ll extra = 0;
		for (auto it = manha.rbegin(); it != manha.rend(); it++) {
			int atual = *it;
			auto parIt = --noite.end();

			int e1 = abs(limiteHoraExtra - (atual + par));
			noite.erase(parIt);
			extra += e1;
		}

		cout<<extra*taxaHoraExtra<<endl;
	}

	return 0;
}