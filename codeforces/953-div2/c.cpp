#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;
		if (k > n*n/2 || k%2) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			vector<int> permutation;
			for (int i = 0; i < n; i++) {
				permutation.push_back(i+1);
			}

			for (int i = 0; i < n/2; i++) {
				if (k >= 2 * (n-2*i-1)) {
					swap(permutation[i], permutation[n-i-1]);
				} else {
					swap(permutation[i], permutation[i+(k/2)]);
					break;
				}

				k -= 2 * (n-2*i-1);
			}

			for (int i = 0; i < n; i++) {
				cout<<permutation[i]<<" ";
			}

			cout<<endl;
		}
	}

	return 0;
}