#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;
		vector<int> cans;
		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			cans.push_back(val);
		}

		sort(cans.begin(), cans.end());
		int total = 0;
		int index = 0;	
		int presses = 0;
		int remover = 0;

		while (total < k) {
			cans[index] -= remover;
			remover += cans[index];
			presses += min((n-index) * cans[index], k-total);
			total += (n-index) * cans[index];
			if(total < k) presses++;
			index++;
		}

		cout<<presses<<endl;
	}

	return 0;
}