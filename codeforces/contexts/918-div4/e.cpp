#include<bits/stdc++.h>
#define int long long
using namespace std;

int valores[100005];
int valores2[100005];

int prefix[100005];
int prefix2[100005];


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		for (int i = 0; i < n; i++) {
			if (i%2 == 0) {
				cin>>valores[i/2];
			} else {
				cin>>valores2[i/2];
			}
		}

		prefix[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (i%2) prefix[i] = prefix[i-1] + valores[i-1];
			else prefix[i] = prefix[i-1];
		}

		prefix2[0] = 0;
		for (int i = 1; i <= n; i++) {
			if (i%2 == 0) prefix2[i] = prefix2[i-1] + valores2[i-1];
			else prefix2[i] = prefix2[i-1];
		}


		int passa = 0;
		for (int r = 1; r <= n && !passa; r++) {
			for (int l = 0; l < r-1; l++) {
				cout<<l<<" "<<r<<" "<<prefix[r]<<" "<<prefix[l]<<endl;
				if ((prefix[r] - prefix[l]) == (prefix2[r]-prefix2[l])) {
					//cout<<r<<" "<<l<<endl;
					passa = 1;
					break;
				}
				// if (r%2 == l%2) {
				// 	if ((prefix[r] - prefix[l]) == (prefix2[r-1]-prefix2[l])) {
				// 		//cout<<r<<" "<<l<<endl;
				// 		passa = 1;
				// 		break;
				// 	}
				// } else {
				// 	if ((prefix[r-1] - prefix[l]) == (prefix2[r]-prefix2[l])) {
				// 		//cout<<r<<" "<<l<<endl;
				// 		passa = 1;
				// 		break;
				// 	}
				// }
			}
		}

		if (passa) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}	

	return 0;
}