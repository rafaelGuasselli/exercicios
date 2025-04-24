#include<bits/stdc++.h>
using namespace std;

signed main() {
	int t; cin>>t;

	while (t--) {
		int x, y, k; cin>>x>>y>>k;
		cout<<0<<" "<<0<<" "<<min(x, y)<<" "<<min(x, y)<<endl;
		cout<<0<<" "<<min(x, y)<<" "<<min(x, y)<<" "<<0<<endl;
	}

	return 0;
}