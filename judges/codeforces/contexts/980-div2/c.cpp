#include<bits/stdc++.h>
#define int long long
using namespace std;
	

pair<int, pair<int, int>> pares[100005];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;
		for (int i = 0; i < n; i++) {
			cin>>pares[i].second.first;
			cin>>pares[i].second.second;
			pares[i].first = pares[i].second.first + pares[i].second.second;
		}
	
		sort(pares, pares+n);
		for (int i = 0; i < n; i++) {
			cout<<pares[i].second.first<<" "<<pares[i].second.second<<" ";
		}

		cout<<endl;
	}
	
	return 0;
}