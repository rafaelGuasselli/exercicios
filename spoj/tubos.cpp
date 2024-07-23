#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int countOrd, nBridges;
int low[1001];
int ord[1001];


void dfs(int u, int p) {
	ord[u] = low[u] = countOrd++;

	for (int v: adj[u]) {
		if (v == p) {
			continue;
		}

		if (ord[v] == -1) {
			dfs(v, u);
			if (low[v] > ord[u]) {
				nBridges++;
			}

			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], ord[v]);
		}
	}
}

int main() {
	int nVertices, nEdges; 
	while (cin>>nVertices>>nEdges) {
		if (nVertices == 0 && nEdges == 0) {
			break;
		}

		for (int i = 0; i < nVertices; i++) {
			adj[i].clear();
			ord[i] = -1;
			low[i] = -1;
		}

		countOrd = 0;
		nBridges = 0;
		for (int i = 0; i < nEdges; i++) {
			int u, v; cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0, -1);
		if (nBridges > 0) {
			cout<<"N"<<endl;
		} else {
			cout<<"S"<<endl;
		}
	}
	return 0;
}