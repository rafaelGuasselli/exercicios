#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	int t; cin>>t;
	while (t--) {
		int result = 0;
		
		for (int i = 0; i < 3; i++) {
			int val; cin>>val;
			result ^= val;
		}

		cout<<result<<endl;
	}

	return 0;
}