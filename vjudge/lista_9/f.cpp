#include<bits/stdc++.h>

using namespace std;

int nTests, nVertices, nEdges, totalTime, exitVertice;
int matrix[105][105];

int main() {
	cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		cin>>nVertices>>exitVertice>>totalTime>>nEdges;

		for (int i = 1; i <= nVertices; i++) {
			for (int j = 1; j <= nVertices; j++) {
				if (i != j) {
					matrix[i][j] = 100000000;
				}
			}
		}

		for (int i = 0; i < nEdges; i++) {
			int u, v, t; cin>>u>>v>>t;
			matrix[u][v] = t;
		}

		for (int k = 1; k <= nVertices; k++) {
			for (int i = 1; i <= nVertices; i++) {
				for (int j = 1; j <= nVertices; j++) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		int total = 0;
		for (int i = 1; i <= nVertices; i++) {
			if (matrix[i][exitVertice] <= totalTime) {
				total++;
			}
		}

		if (t > 0) {
			cout<<endl;
		} 


		cout<<total<<endl;
	}

	return 0;
}