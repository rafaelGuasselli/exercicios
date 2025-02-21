#include<bits/stdc++.h>
#define max(a, b) a > b ? a : b 
#define min(a, b) a > b ? b : a 
//#define int long long
using namespace std;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n, limit; cin>>n>>limit;
		int count = 0;
		for (int i = 0; i < n; i++) {
			string curr; cin>>curr;
			if (limit >= curr.size()) {
				limit -= curr.size();
				count++;
			} else {
				limit = 0;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}