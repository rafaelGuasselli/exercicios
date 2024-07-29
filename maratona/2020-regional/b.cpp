#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200000];
int marked[200000];
int total = 1;
vector<pair<int, pair<int, int>>> edges;

void dfs(int vertice) {
	if (!marked[vertice]) {
		total++;
	}

	marked[vertice] = 1;
	for (int child: adj[vertice]) {
		if (!marked[child]) {
			dfs(child);
		}
	}
}

int main() {
	int nVertices, nEdges, k; cin>>nVertices>>nEdges>>k;
	
	for (int i = 0; i < nEdges; i++) {
		int u, v, c; cin>>u>>v>>c;
		edges.push_back({c, {u-1, v-1}});
	}

	marked[0] = 1;
	sort(edges.begin(), edges.end());

	for (pair<int, pair<int, int>> edge: edges) {
		int u = edge.second.first;
		int v = edge.second.second;
		int c = edge.first;

		adj[u].push_back(v);
		adj[v].push_back(u);

		if (marked[u]) {
			dfs(v);
		}  
		
		if (marked[v]) {
			dfs(u);
		}

		if (total >= k) {
			cout<<c<<endl;
			break;
		}
	}

	return 0;	
}