#include<bits/stdc++.h>
#define MAX_N 30
#define ll long long

using namespace std;


ll memo[MAX_N][MAX_N] = {0};
int n, an1;

ll formula(int i, int j){
	if (memo[i][j] > 0) {
		return memo[i][j];
	}

	if (i >= j) {
		memo[i][j] = 0;
		if (j > 0) {
			ll value = 0;
			for (int k = 1; k < j; k++) {
				value = max(value, formula(i, k) + formula(n, k));
			}
			
			memo[i][j] += value;
		}

		if (i < n) {
			ll value = 0;
			for (int k = i+1; k <= n; k++) {
				value = max(value, formula(k, 1) + formula(k, j));
			}

			memo[i][j] += value;
		}
	} else {
		ll value = 0;
		for (int k = i; k < j; k++) {
			value = max(value, formula(i, k) + formula(k+1, j));
		}

		memo[i][j] = value;
	}


	return memo[i][j];
}

int main(){
	while (cin>>n>>an1) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				memo[i][j] = 0;
			}
		}

		memo[n][1] = an1;
		cout<<formula(1, n)<<endl;
	}

	return 0;
}