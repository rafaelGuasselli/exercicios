#include<bits/stdc++.h>

using namespace std;


int edges[100][100];
int dominates[]
int marked[100];
int parent[100];
int size;

int dfs(int edge, int parent) {	
	marked[edge] = 1;
	
	if (parent[edge] == -1) {
		parent[edge] = parent;
	} else {
		parent[edge] = parent[parent];	
	}

	for (int i = 0; i < size) {
		if (!marked[i] && edges[edge][i]) {
			dfs(i, edge);
		}
	}
}

int main() {
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		cin>>size;

		for (int l = 0; l < size; l++) {
			for (int c = 0; c < size; c++) {
				cin>>edges[l][c];
			}
		}

		for (int i = 0; i < size; i++) {
			parent[i] = -1;
			marked[i] = 0;
		}

		parent[0] = 0;

	}

    return 0;
}