#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int a, b; cin>>a>>b;
		int x = max(b-a, 0);
		int result = max(a-x, 0);
		cout<<result<<endl;
	}

	return 0;
}