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

		vector<int> manha;
		vector<int> noite; 

		for (int i = 0; i < qtdEntregas; i++) {
			int m, n; cin>>m>>n;
			manha.push_back(m);
			noite.push_back(n);
		}

		sort(manha.begin(), manha.end(), greater<int>());
		sort(noite.begin(), noite.end());
		

		ll extra = 0;
		auto noiteIt = noite.begin();
		for (int manhaAtual: manha) {
			extra += taxaHoraExtra * max(0, (*noiteIt + manhaAtual) - limiteHoraExtra);
			noiteIt++;
		}

		cout<<extra<<endl;
	}

	return 0;
}