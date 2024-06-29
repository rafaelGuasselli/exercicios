#include<bits/stdc++.h>
#define ll long long
<<<<<<< HEAD
using namespace std;

int nVertices, nEdges;
ll matrix[305][305];
ll newMatrix[305][305];
vector<pair<int, int>> edges;

int main(){	
	cin>>nVertices>>nEdges;
	
	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			if (i == j) {
				matrix[i][j] = 0;
			} else {
				matrix[i][j] = 1000000;
			}
		}
	}
	
	for (int i = 0; i < nEdges; i++) {
		ll u,v,d; cin>>u>>v>>d;
		u--; v--;
		matrix[u][v] = d;
		matrix[v][u] = d;
		edges.push_back({u, v});
	}

	for (int k = 0; k < nVertices; k++) {
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < nVertices; j++) {
				if (i != j && i != k && j != k) {
					matrix[i][j] = min(newMatrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	for (pair<int, int> edge: edges) {
		int distance = newMatrix[edge.first][edge.second];
		if (distance == 1000000) {
			cout<<"-1"<<endl;
		} else {
			cout<<distance<<endl;
		}
	}
=======

using namespace std;

int nVertices, nEdges;
ll adj[300][300];

int main() {
	cin>>nVertices>>nEdges;

	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++) {
			adj[i][j] = 1000000000000000000;
		}
	}
	
	
>>>>>>> cb60717d5c63851e59ee78e6ce7e8d9fc9253e82

	return 0;
}