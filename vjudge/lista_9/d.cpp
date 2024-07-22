#include<bits/stdc++.h>
#define ll long long
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
				matrix[i][j] = 10000000000000000;
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

	for (pair<int, int> edge: edges) {
		for (int i = 0; i < nVertices; i++) {
			for (int j = 0; j < nVertices; j++) {
				newMatrix[i][j] = matrix[i][j];
			}
		}

		newMatrix[edge.first][edge.second] = 10000000000000000;
		newMatrix[edge.second][edge.first] = 10000000000000000;
		
		for (int k = 0; k < nVertices; k++) {
			for (int i = 0; i < nVertices; i++) {
				for (int j = 0; j < nVertices; j++) {
					newMatrix[i][j] = min(newMatrix[i][j], newMatrix[i][k] + newMatrix[k][j]);
				}
			}
		}

		int distance = newMatrix[edge.first][edge.second];
		if (distance == 10000000000000000) {
			cout<<"-1"<<endl;
		} else {
			cout<<distance<<endl;
		}
	}

	return 0;
}