#include<bits/stdc++.h>
//#define int long long
using namespace std;


char matrix[1005][1005];
char valor[4] = {'1', '5', '4', '3'};

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n, m; cin>>n>>m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin>>matrix[i][j];
			}
		}

		int total = 0;
		for (int l = 0; l < min(n, m)/2; l++) {
			vector<char> line;
			for (int j = l; j < m-l; j++) {
				line.push_back(matrix[l][j]);
			}

			for (int i = l+1; i < n - l; i++) {
				line.push_back(matrix[i][m-l-1]);
			}

			for (int j = m-l-2; j >= l; j--) {
				line.push_back(matrix[n-l-1][j]);
			}

			for (int i = n-l-2; i > l; i--) {
				line.push_back(matrix[i][l]);
			}

			line.push_back(line[0]);
			line.push_back(line[1]);
			line.push_back(line[2]);

			int ind = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == valor[ind]) {
					ind++;
					if (ind == 4) {
						ind = 0;
						total++;
					}
				} else if (line[i] == valor[0]){
					ind = 1;
				} else {
					ind = 0;
				}
			}
		}

		cout<<total<<endl;
	}

	return 0;
}