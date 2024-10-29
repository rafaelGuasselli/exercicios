#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int t; cin>>t;

	while (t--) {
		int n; cin>>n;
		string s; cin>>s;

		int total = 0;
		int remover = 0;
		int inicio = 0;
		int count = n;

		for (int i = n; i >= 1; i--) {
			total += i;
			if (s[i-1] == '1') {
				if (count >= 2 && i >= 2) {
					remover += i;
					count = min(i-2, count-2);
				}
			}
		}

		cout<<total-remover<<endl;
	}

	return 0;
}