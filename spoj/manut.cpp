#include<bits/stdc++.h>
using namespace std;


int nVertices, nEdges, root, rootChildren;
vector<int> adj[405];
bitset<405> articulations;
int ordCount;
int low[405];
int ord[405];

void dfs(int u, int parent) {
	ord[u] = low[u] = ordCount++;

	for (int v: adj[u]) {
		if (v == parent) continue;
		if (ord[v] == -1) {
			if (u == root) rootChildren++; 
			dfs(v, u);

			if (low[v] >= ord[u]) {
				articulations.set(u);
			}

			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], ord[v]);
		}
	}
}

int main() {
	int test = 1;
	while (scanf("%d %d", &nVertices, &nEdges) != EOF) {
		if (nVertices == 0 && nEdges == 0) {
			break;
		}

		articulations.reset();
		ordCount = 0;
		for (int i = 0; i < nVertices; i++) {
			low[i] = ord[i] = -1;
			adj[i].clear();
		}

		for (int i = 0; i < nEdges; i++) {
			int u, v; scanf("%d %d", &u, &v);
			u--; v--;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 0; i < nVertices; i++) {
			if (ord[i] == -1) {
				root = i; rootChildren = 0;
				dfs(i, -1);
				if (rootChildren > 1) {
					articulations.set(i);
				} else {
					articulations.reset(i);
				}
			}
		}

		printf("Teste %d\n", test++);
		int count = 0;
		for (int i = 0; i < nVertices; i++) {
			if (articulations.test(i)) {
				if (count > 0) {
					printf(" ");
				}

				printf("%d", i+1);
				count++;
			}
		}
		if (count == 0) {
			printf("nenhum");
		}

		printf("\n\n");
	}
	return 0;
}