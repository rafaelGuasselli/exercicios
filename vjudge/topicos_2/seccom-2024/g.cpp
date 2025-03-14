#include<bits/stdc++.h>
#define int long long
using namespace std;


pair<int,int> cows[10005];
int alocados[10005];

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;cin>>n;

	int maiorTempo = 0;
    for(int i = 0; i < n; i++) {
        cin>>cows[i].first>>cows[i].second;
		maiorTempo = max(maiorTempo, cows[i].second);
		cows[i].second--;
    }

	sort(cows, cows+n, greater<pair<int, int>>());
	for (int i = 0; i < n; i++) {
		int saldo = cows[i].first;
		int tempo = cows[i].second;
		
		while (tempo >= 0 && saldo <= alocados[tempo]) {
			tempo--;
		}

		if (tempo >= 0) {
			alocados[tempo] = saldo;
		}
	}

	int soma = 0;
	for (int i = 0; i < maiorTempo; i++) {
		soma += alocados[i];
	}

	cout<<soma<<endl;
    return 0;
}