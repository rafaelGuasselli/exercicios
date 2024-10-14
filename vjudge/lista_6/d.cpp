#include<bits/stdc++.h>
#define int long long
using namespace std;

int memo[51][51][51];

int b(int n, int k, int m){
	if (k*m < n) {
		return 0;
	}

	if (n < 1) {
		return 0;
	}

	if (k == 1) {
		return 1;
	}

	if (n == k) {
		return 1;
	}

	if (memo[n][k][m] != -1) {
		return memo[n][k][m];
	}

	int result = 0;
	for (int i = 1; i <= m; i++) {
		result += b(n-i, k-1, m);
	}

	memo[n][k][m] = result;
	return result;
}

signed main() {
	memset(memo, -1, sizeof(memo));

	while (!cin.eof()) {
		string input;
		getline(cin, input);
		if (input.size() == 0) {
			break;
		}

		stringstream stream(input);
		int n, k, m; stream>>n>>k>>m;
		cout<<b(n, k, m)<<endl;
	}

	return 0;
}