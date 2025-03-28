#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;


vector<int> adj[300005];
int tin[300005];
int tout[300005];
int timer; 

void dfs(int u) {
	tin[u] = timer++;

	for (int v: adj[u]) {
		dfs(v);
	}	

	tout[u] = timer++;
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, q; cin>>n>>q;
	for (int i = 1; i < n; i++) {
		int u; cin>>u; u--;
		adj[u].push_back(i);
	}	

	timer = 0;
	dfs(0);

	for (int i = 0; i < q; i++) {
		int m; cin>>m;
		vector<pair<int, int>> ranges;
		for (int i = 0; i < m; i++) {
			int f; cin>>f; f--;
			ranges.push_back({tout[f], tin[f]});
		}

		sort(ranges.begin(), ranges.end());

		int limit = -1;
		int count = 0;
		for (pair<int, int> r: ranges) {
			if (r.second > limit) {
				count++;
				limit = r.first;
			}
		}

		cout<<count<<endl;
	}


	return 0;
}