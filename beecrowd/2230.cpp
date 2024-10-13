#include<bits/stdc++.h>

using namespace std;

vector<int> adj[51];
int distTo[51];


int main(){
	int nVertices, nEdges, sVertice, maxPedagios;
	int instancia = 1;
	while (cin>>nVertices>>nEdges>>sVertice>>maxPedagios) {
		if (nVertices == 0 && nEdges == 0 && sVertice == 0 && maxPedagios == 0) {
			break;
		}

		for (int i = 0; i < 51; i++) {
			adj[i].clear();
		}

 		sVertice--;
		for (int i = 0; i < nEdges; i++) {
			int u, v; cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 0; i < 51; i++) {
			distTo[i] = 1e9;
		}

		queue<int> q;
		q.push(sVertice);
		distTo[sVertice] = 0;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			int d = distTo[u]; 

			for (int v: adj[u]) {
				if (d+1 < distTo[v]) {
					distTo[v] = d+1;
					q.push(v);
				}
			}
		}

		cout<<"Teste "<<instancia++<<endl;
		for (int i = 0; i < 51; i++) {
			if (i == sVertice) continue; 
			if (distTo[i] <= maxPedagios) {
				cout<<i+1<<" ";
			}
		}

		cout<<endl<<endl;
	}

	return 0;
}