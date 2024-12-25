#include<bits/stdc++.h>

using namespace std;

int valores[105];
bitset<105> dp[10010];


signed main() {
	int n; cin>>n;

	int target = 0;
	for (int i = 0; i < n; i++) {
		cin>>valores[i];
		target += valores[i];
	}

	if (n == 1 || target%2) {
		cout<<-1<<endl;
		return 0;
	}

	for (int i = 0; i < target; i++) {
		dp[i].reset();
	}

	target /= 2;
	
	for (int i = 0; i < n && dp[target].count() == 0; i++) {
		for (int k = target; k >= 1; k--) {
			if (dp[k].count() > 0) {
				cout<<i<<endl;
				bitset<105> copy(dp[k]);
				dp[k+valores[i]] = copy;
				dp[k+valores[i]].set(i);

				if (k+valores[i] == target) {
					break;
				}	
			}
		}
		dp[valores[i]].set(i);
	}

	if (dp[target].count() == 0) {
		cout<<-1<<endl;
		return 0;
	}

	vector<int> primeiro;
	vector<int> segundo;
	for (int i = 0; i < n; i++) {
		if (dp[target].test(i)) {
			primeiro.push_back(valores[i]);
		} else {
			segundo.push_back(valores[i]);
		}
	}

	int ind1 = 0;
	int ind2 = 0;
	int soma = 0;

	for (int i = 0; i < n; i++) {
		if (soma >= 0) {
			soma -= primeiro[ind1];
			cout<<primeiro[ind1++]<<" ";
		} else {
			soma += segundo[ind2];
			cout<<segundo[ind2++]<<" "; 
		}
	}

	cout<<endl;
	return 0;
}