#include<bits/stdc++.h>
#define int long long
using namespace std;

int valores[100005];
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin>>n;
	int menor = 1e18;
	for (int i = 0; i < n; i++) {
		cin>>valores[i];
		menor = min(menor, valores[i]);
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += valores[i] - menor;	
	}

	cout<<sum<<endl;
	return 0;
}