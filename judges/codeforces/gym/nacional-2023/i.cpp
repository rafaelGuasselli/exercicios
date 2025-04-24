#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9+7;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string s; cin>>s;
	int n; cin>>n; n %= mod;

	int countChars[30] = {0}; 
	int inversions = 0;

	for (char c: s) {
		int charId = c-'a';
		countChars[charId]++;
		for (int i = 29; i > charId; i--) {
			inversions += countChars[i];
			inversions %= mod;
		}
	}

	inversions *= n;
	inversions %= mod;

	for (char c: s) {
		int charId = c-'a';
		int smaller = 0;
		for (int i = 0; i < charId; i++) {
			smaller += countChars[i];
			smaller %= mod;
		}

		int factor = n * (n-1)/2;
		factor %= mod;

		inversions += smaller * factor;
		inversions %= mod;
	}

	cout<<inversions<<endl;
	return 0;
}