#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;
<<<<<<< HEAD

int matrix[305][305];
int qVal[305];

=======
 
int matrix[305][305];
int qVal[305];
 
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
<<<<<<< HEAD

=======
 
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin>>matrix[i][j];
			}
		}
<<<<<<< HEAD

=======
 
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
		memset(qVal, 0, sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j >= 0; j--) {
				if (matrix[i][j] != 1) {
					break;
				}
<<<<<<< HEAD

				qVal[i]++;
			}
		}

=======
 
				qVal[i]++;
			}
		}
 
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
		sort(qVal, qVal+n);
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (qVal[i] >= count) {
				count++;
			}
		}
<<<<<<< HEAD

		cout<<count<<endl;
	}

=======
 
		cout<<count<<endl;
	}
 
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
	return 0;
}