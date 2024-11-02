#include<bits/stdc++.h>
//#define int long long
using namespace std;



signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;

		vector<char> s;
		for (int i = 0; i < n; i++) {
			char val; cin>>val;
			s.push_back(val);
		}

		int atual = s[0] == '1' || s[n-1] == '1';
		for (int i = 0; i < n-1; i++) {
			if (s[i] == '1' && s[i+1] == '1') {
				atual = 1;
				break;
			}
		}

		if (atual == 1) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}