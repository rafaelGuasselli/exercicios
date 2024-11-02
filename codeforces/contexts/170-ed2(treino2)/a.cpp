#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		string s1;
		string s2; cin>>s1>>s2;
		int total = s1.size() + s2.size();;

		int remover = -1;
		for (int i = 0; i < min(s1.size(), s2.size()); i++) {
			if (s1[i] != s2[i]) {
				break;
			}

			remover++;
		}

		cout<<total-max(remover, 0)<<endl;
	}

	return 0;
}