#include<bits/stdc++.h>
#define int long long
using namespace std;

int memo[60][60];

int b(int n, int k, int m){
	if (n == k) {
		return 1;
	} 


	if (memo[n][k] != -1) {
		return memo[n][k];
	}

	int result = 0;
	for (int i = 1; i <= m && (n-i) >= 0 && k > 0; i++) {
		result += b(n-i, k-1, m);
	}

	memo[n][k] = result;
	return result;
}

signed main() {
	while (!cin.eof()) {
		string input;
		getline(cin, input);
		if (input.size() == 0) {
			break;
		}

		stringstream stream(input);
		int n, k, m; stream>>n>>k>>m;
		for (int ki = 0; ki <= k; ki++) {
			for (int ni = 0; ni <= n; ni++) {
				if (ni == ki) {
					memo[ni][ki] = 1;
				} else {
					memo[ni][ki] = 0;
				}
			}
		}

		for (int ki = 1; ki <= k; ki++) {
			for (int ni = 1; ni <= n; ni++) {
				memo[ni][ki] = 0;
				for (int mi = 1; mi <= m && (ni-mi) >= 0; mi++) {
					memo[ni][ki] += memo[ni-mi][ki-1];
				}
			}
		}

		cout<<memo[n][k]<<endl;
	}

	return 0;
}