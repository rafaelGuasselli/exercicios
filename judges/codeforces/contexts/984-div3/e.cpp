#include<bits/stdc++.h>
//#define int long long
using namespace std;


int matrix[100005];
int regions[100005];


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k, q; cin>>n>>k>>q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin>>matrix[i*k+j];
		}
	}

	for (int i = 0; i < k; i++) {
		regions[i*n] = matrix[i];

		for (int j = 1; j < n; j++) {
			matrix[j*k+i] = matrix[j*k+i] | matrix[(j-1)*k+i];
			regions[i*n+j] = matrix[j*k+i];
		}
	}


	for (int i = 0; i < q; i++) {
		int r; cin>>r;
		int menorInd = 0;
		int maiorInd = n;

		for (int j = 0; j < r; j++) {
			int ki; cin>>ki; ki--;
			char op; cin>>op;
			int c; cin>>c;

			if (op == '<') {
				int ind = lower_bound(regions + (ki*n), regions + (ki*n+n), c) - (regions + (ki*n));
				maiorInd = min(maiorInd, ind-1);
			} else {
				int ind = upper_bound(regions + (ki*n), regions + (ki*n+n), c) - (regions + (ki*n));
				menorInd = max(menorInd, ind);
			}
		}

		if (menorInd <= maiorInd && menorInd < n) {
			cout<<menorInd+1<<endl;
		} else {
			cout<<-1<<endl;
		}
	}

	return 0;
}