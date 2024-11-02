#include<bits/stdc++.h>
//#define int long long
using namespace std;



signed main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;

		int maior = 0;
		int menor = 1e9; 
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin>>a[i];
			maior = max(a[i], maior);
			menor = min(a[i], menor);
		}

		int pontos = 0;
		for (int i = 0; i < (n-1); i++) {
			pontos += (maior - menor);
		}

		cout<<pontos<<endl;
	}

	return 0;
}