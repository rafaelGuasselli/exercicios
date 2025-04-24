#include<bits/stdc++.h>
#define int long long
using namespace std;


int mod = 1e9+7;
int potencias[100001];

signed main() {
    int t; cin>>t;
	vector<int> n(t);
	vector<int> k(t);
	for (int i = 0; i < t; i++) {
		cin>>n[i];
	}

	for (int i = 0; i < t; i++) {
		cin>>k[i];
	}

	potencias[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		potencias[i] = (potencias[i-1] * 2) % mod;
	}

	for (int i = 0; i < t; i++) {
		cout<<potencias[k[i]]<<endl;
	}

	return 0;
}