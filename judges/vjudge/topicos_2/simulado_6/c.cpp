#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll mod = 1e9+7;
int main() {
	int nTests; cin>>nTests;
	

	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;
		if (n-k > 365) {
			cout<<0<<endl;
		} else {
			ll result = 1;
			for (int i = 365; i > n-k; i--) {
				result = (result * i) % mod;
			}
		}
	}
}