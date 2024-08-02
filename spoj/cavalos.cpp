#include<bits/stdc++.h>
#define ll long long

using namespace std;

int residue[500][500];
vector<int> adj[500];
vector<int> parent;
vector<int> visited;
int s, t, nVertices, nCavalos, nSoldados, nEdges, maxflow;

int hasPath() {
	parent.clear();
	visited.clear();
	parent.assign(nVertices, -1);
	visited.assign(nVertices, 0);

	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = s;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (u == t) break;
		for (int v: adj[u]) {
			if (residue[u][v] > 0 && !visited[v]) {
				q.push(v);
				parent[v] = u;
				visited[v] = 1;
			}
		}
	}

	return visited[t];    
}

int main() {
	int instancia = 1;
	while(cin>>nCavalos>>nSoldados>>nEdges) {
		nVertices = nCavalos+nSoldados+5;
		s = nVertices-2;
		t = nVertices-1;
		maxflow = 0;

		for (int i = 0; i < nVertices; i++) {
			adj[i].clear();
			for (int j = 0; j < nVertices; j++) {
				residue[i][j] = 0;
			}
		}

		for (int i = 0; i < nCavalos; i++) {
			int capacity; cin>>capacity;
			residue[i][t] = capacity;
			adj[i].push_back(t);
			adj[t].push_back(i);
		}

		for (int i = 0; i < nEdges; i++) {
			int u, v; cin>>u>>v;
			v += nCavalos-1; u--;
			
			residue[v][u] = 1;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}

		for (int i = 0; i < nSoldados; i++) {
			int v = i+nCavalos;
			adj[s].push_back(v);
			adj[v].push_back(s);
			residue[s][v] = 1;
		}

		while (hasPath()) {
			int bottleneck = 1e9;
			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v];
				bottleneck = min(bottleneck, residue[u][v]);
			}

			for (int v = t; v != s; v = parent[v]) {
				int u = parent[v];
				residue[u][v] -= bottleneck;
				residue[v][u] += bottleneck;
			}

			maxflow += bottleneck;
		}

		cout<<"Instancia "<<instancia++<<endl;
		cout<<maxflow<<endl;
		cout<<endl;
	}

	return 0;
}