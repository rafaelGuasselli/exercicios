#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int mod = 998244353;
int somas[10001];
int valores[6000];
 
 
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>valores[i];
	}
 
	sort(valores, valores+n);
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int sum = 5000; sum >= 0; sum--) {
			somas[sum+valores[i]] = (somas[sum+valores[i]] + somas[sum]) % mod;
 
			int sumK = sum+valores[i];
			if (2*valores[i] >= sumK) {
				total = (total + somas[sum] * valores[i]) % mod;
			} else {
				total = (total + (somas[sum]% mod)*(int)ceil((sumK% mod)/2.0)) % mod;
			}
		}
 
		somas[valores[i]]++;
		total = (total + valores[i]) % mod;
	}
 
	cout<<total<<endl;
	return 0;
}