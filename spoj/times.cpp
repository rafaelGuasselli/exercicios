#include<bits/stdc++.h>

using namespace std;

int main() {
	int nJogadores, nTimes; cin>>nJogadores>>nTimes;
	vector<pair<int, string>> jogadores;	
	vector<multiset<string>> times(nTimes);

	for (int i = 0; i < nJogadores; i++) {
		string nome; int habilidade; cin>>nome>>habilidade;
		jogadores.push_back({habilidade, nome});
	}

	sort(jogadores.begin(), jogadores.end(), greater<pair<int, string>>());
	for (int i = 0; i < nJogadores; i++) {
		times[i%nTimes].insert(jogadores[i].second);
	}

	for (int i = 0; i < nTimes; i++) {
		cout<<"Time "<<i+1<<endl;
		for (string nome: times[i]) {
			cout<<nome<<endl;
		}
		cout<<endl;
	}

	return 0;
}