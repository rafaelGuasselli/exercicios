	#include<bits/stdc++.h>

	using namespace std;


	int main(){
		int n; 
		int instancia = 1;
		while (cin>>n) {
			if (n == 0) {
				break;
			}

			vector<pair<int, string>> jogadores;
			for (int i = 0; i < n; i++) {
				string name; cin>>name;
				int pontos = 0;
				int menor = 1e9;
				int maior = 0;
				for (int j = 0; j < 12; j++) {
					int p; cin>>p;
					pontos+=p;
					menor = min(menor, p);
					maior = max(maior, p);
				}

				pontos = pontos - menor - maior;
				jogadores.push_back({-pontos, name});
			}

			sort(jogadores.begin(), jogadores.end());
			cout<<"Teste "<<instancia++<<endl;
			int pos = 0;
			int next =1;
			int previous = 0;
			for (int i = 0; i < jogadores.size(); i++) {
				if (jogadores[i].first != previous) {
					pos += next;
					next = 1;
				} else {
					next++;
				}

				previous = jogadores[i].first;
				cout<<pos<<" "<<-jogadores[i].first<<" "<<jogadores[i].second<<endl;
			}	
			cout<<endl;
		}

		return 0;
	}