#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		double result = 0;
		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			result += val;
		}

		result = sqrt(result);
		if (floor(result) == result) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}