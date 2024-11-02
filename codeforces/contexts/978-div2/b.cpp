#include<bits/stdc++.h>
using namespace std;
#define int long long
	
signed main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, x; cin>>n>>x;
		int maior = 0;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			sum += val;
			maior = max(maior, val);
		}

		cout<<max(maior, (sum+x-1)/x)<<endl;
	}
	return 0;
}