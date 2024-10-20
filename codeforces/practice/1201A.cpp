#include<bits/stdc++.h>
//#define int long long
using namespace std;

int freq[1000][1000];

signed main() {
	int n, m; cin>>n>>m;
	for (int i = 0; i < n; i++) {
		string respostas; cin>>respostas;
		for (int j = 0; j < m; j++) {
			freq[j][respostas[j]-'A']++;
		}
	}

	int total = 0;
	for (int i = 0; i < m; i++) {
		int pontos; cin>>pontos;
		int maximo = *max_element(freq[i], freq[i]+5);
		total += pontos * maximo;
	}

	cout<<total<<endl;
	return 0;
}