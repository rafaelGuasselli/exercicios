#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int low[100005];
int ord[100005];
int ordCount;
int nCities; 
int smallestDif;

void dfs(int u, int p){ 
	low[u] = ord[u] = ordCount++;

	for (int v: adj[u]) {
		if (v == p) continue;
		if (ord[v] == -1) {
			dfs(v, u);

			if (low[u] < low[v]) {
				int reachebleVertices = ordCount - ord[v];
				int half = nCities - reachebleVertices;

				smallestDif = min(smallestDif, abs(half-reachebleVertices));
			}

			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], ord[v]);
		}
	}
}

int main() {
	cin>>nCities;
	for (int i = 0; i < nCities-1; i++) {
		int u, v; cin>>u>>v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(low, -1, sizeof(low));
	memset(ord, -1, sizeof(ord));
	ordCount = 0;
	smallestDif = 1e9;
	dfs(0, -1);
	cout<<smallestDif<<endl;
	return 0;
}