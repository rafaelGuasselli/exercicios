#include<bits/stdc++.h>
#define int long long
using namespace std;


vector<vector<int>> matrix;
vector<vector<int>> maior;
vector<vector<int>> menor;


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k, q; cin>>n>>k>>q;
	maior.assign(k, {});
	menor.assign(k, {});
	
	for (int i = 0; i < n; i++) {
		matrix.push_back({});
		for (int j = 0; j < k; j++) {
			int val; cin>>val;
			matrix[i].push_back(val);
		}
	}

	for (int i = 0; i < k; i++) {
		// maior[0].push_back(matrix[i][0]);
		// menor[0].push_back(-matrix[i][0]);

		for (int j = 1; j < n; j++) {
			matrix[j][i] = matrix[j][i] | matrix[j-1][i];
			// maior[j].push_back(matrix[i][j]);
			// menor[j].push_back(-matrix[i][j]);
		}
	}

	cout<<"a"<<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i = 0; i < q; i++) {
		int r; cin>>r;
		int menorInd = 0;
		int maiorInd = n-1;

		for (int j = 0; j < r; j++) {
			int ki; cin>>ki; ki--;
			char op; cin>>op;
			int c; cin>>c;

			if (op == '<') {
				int ind = upper_bound(menor[ki].begin(), menor[ki].end(), -c)-menor[ki].begin();
				maiorInd = min(maiorInd, ind);
			} else {
				int ind = upper_bound(maior[ki].begin(), maior[ki].end(), c)-maior[ki].begin();
				menorInd = max(menorInd, ind);
			}
		}

		if (menorInd <= maiorInd) {
			cout<<menorInd+1<<endl;
		} else {
			cout<<-1<<endl;
		}
	}

	return 0;
}