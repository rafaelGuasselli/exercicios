#include<bits/stdc++.h>
//#define int long long
using namespace std;

int isConsonant(char val) {
	return val == 'b' || val == 'c' || val == 'd';
}

signed main() {
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		string s; cin>>s;
		for (int i = 0; i < n; i++) {
			if (i > 0 && i < n-1 && isConsonant(s[i]) && !isConsonant(s[i+1])) {
				cout<<".";
			}

			cout<<s[i];
		}

		cout<<endl;
	}

	return 0;
}