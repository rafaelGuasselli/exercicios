#include<bits/stdc++.h>
#define int long long
using namespace std;

int valores[2005];
int difs[2005];

signed main() {
	int t; cin>>t;

	while (t--) {
		int n; cin>>n;
		memset(difs, 0, sizeof(int) * (n+10));
		memset(valores, 0, sizeof(int) * (n+10));

		for (int i = 0; i < n; i++) {
			cin>>valores[i];
		}


		for (int i = 1; i < n; i++) {
			difs[i-1] = abs(valores[i] - valores[i-1]);
		}

		int maiorPar = 1;
		int maiorImpar = 1;
		for (int i = 0; i < n; i++) {
			if (i%2) {
				maiorImpar = max(maiorImpar, difs[i]);
			} else {
				maiorPar = max(maiorPar, difs[i]);
			}
		}
		
		if (n%2) {
			cout<<min(maiorPar, maiorImpar)<<endl;
		} else {
			cout<<min(maiorPar, max(maiorImpar, min(abs(valores[n-2]-valores[n-1]), abs(valores[0]-valores[1]))))<<endl;
		} 
	}

	return 0;
}