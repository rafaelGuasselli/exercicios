#include<bits/stdc++.h>
using namespace std;

vector<int> adj[300005];
int visited[300005] = {0};

void dfs(int u, int p, int id, int b) {
	visited[u] = id;
	for (int v: adj[u]) {
		if(v==p) continue;
		if(v==b) continue;
		if (!visited[v]) {
			dfs(v, u, id, b);
		}
	}
}

signed main() {
	int n, m; cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(n-2, -1, 1, n-1);
	dfs(n-1, -1, 2, -1);

	for (int i = 0; i < n; i++) {
		cout<<(visited[i] == 2 ? "A" : "B");
	}
	cout<<endl;
	
	return 0;
}