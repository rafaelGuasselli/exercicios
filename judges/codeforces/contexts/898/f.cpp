#include<bits/stdc++.h>
#define int long long
using namespace std;

int alturas[200005];
int frutas[200005];
signed main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;

		for (int i = 0; i < n; i++) {
			cin>>frutas[i];
		}

		for (int i = 0; i < n; i++) {
			cin>>alturas[i];
		}

		vector<pair<int, int>> rangesValidos;
		int inicio = 0;
		for (int i = 0; i < n; i++) {
			if (i == n-1){
				rangesValidos.push_back({inicio, i});
				break;
			}
			if (alturas[i] % alturas[i+1] != 0) {
				rangesValidos.push_back({inicio, i});
				inicio = i+1;
			}
		}

		int closest = 0;
		for (pair<int, int> range: rangesValidos) {
			int sum = 0;
			int inicio = range.first;
			int fim = range.first;

			while(fim <= range.second) {
				sum += frutas[fim];
				if (sum <= k && abs(sum-k) < abs(closest-k)) {
					closest = sum;
					continue;
				}

				while (sum > k) {
					sum -= frutas[inicio];
					inicio++;
				} 

				fim++;
			}
		}

		cout<<closest<<endl;
	}	

	return 0;
}