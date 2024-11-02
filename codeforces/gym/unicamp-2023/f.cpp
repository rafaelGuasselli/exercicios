#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> adj[300005];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int nVertices, nEdges; cin>>nVertices>>nEdges;
	for (int i = 0; i < nEdges; i++) {
		int u, v, c; cin>>u>>v>>c;
		u--; v--;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}

	

	return 0;
}