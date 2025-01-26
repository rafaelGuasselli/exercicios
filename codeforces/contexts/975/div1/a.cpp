#include<bits/stdc++.h>
#define int long long
using namespace std;
	


int valores[200005];
signed main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;
		
		int m = 0;
		int maior = 0;
		for (int i = 0; i < n; i++) {
			cin>>valores[i];
			maior = max(maior, valores[i]);
			m += valores[i];
		}

		int foi = 0;
		for (int s = n; s >= 2; s--) {
			if (m % s == 0 && maior <= m/s) {
				cout<<s<<endl;
				foi = 1;
				break;
			} else {
				int start = m/s;
				int end = (m+k)/s;
				if (end > start && maior <= end) {
					cout<<s<<endl;
					foi = 1;
					break;
				}
			}
		}
		if (!foi) cout<<1<<endl;
	}
	
	return 0;
}