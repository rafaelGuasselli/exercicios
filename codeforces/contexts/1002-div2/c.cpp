#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

int matrix[305][305];
int qVal[305];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin>>matrix[i][j];
			}
		}

		memset(qVal, 0, sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= 0; j--) {
				if (matrix[i][j] != 1) {
					break;
				}

				qVal[i]++;
			}
		}

		sort(qVal, qVal+n);
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (qVal[i] >= count) {
				count++;
			}
		}

		cout<<count<<endl;
	}

	return 0;
}