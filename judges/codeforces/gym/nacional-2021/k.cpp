#include<bits/stdc++.h>
using namespace std;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin>>n;
	int p[30] = {0};
	int possivel = 0;
	for (int i = 0; i < n; i++) {
		string pal; cin>>pal;
		p[pal[0]-'A'] = 1;

		int valido = 1;
		for (int c: pal) {
			valido &= p[c-'A'];
		}

		possivel |= valido;
	}

	cout<<(possivel ? "Y" : "N")<<endl;
	return 0;
}