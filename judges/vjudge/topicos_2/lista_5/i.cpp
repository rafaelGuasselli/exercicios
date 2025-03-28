#include <bits/stdc++.h>
using namespace std;

int main() {	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int qtdBaloes; cin>>qtdBaloes;
	multiset<int> baloes;
	int qtd = 0;

	for (int i = 0; i < qtdBaloes; i++) {
		int balao; cin>>balao;
		baloes.insert(balao);

		if (baloes.find(balao+1) != baloes.end()) {
			baloes.erase(baloes.find(balao+1));
			continue;
		}

		qtd++;
	}

	cout<<qtd<<endl;

	return 0;
}