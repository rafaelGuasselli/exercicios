#include<bits/stdc++.h>

using namespace std;


int nTests, nVertices, nEdges;
int color[201];
int marked[201];
int impossible = 0;
int colorCount[2];

vector<int> adj[201];

void dfs(int vertice) {
	if (impossible) {
		return;
	}

	if (marked[vertice]) {
		return;
	}

	marked[vertice] = 1;
	colorCount[color[vertice]]++;

	for (int child: adj[vertice]) {
		if (!marked[child]) {
			color[child] = 1 - color[vertice];
			dfs(child); 
		} else if (color[vertice] == color[child]) {
			impossible = 1;
		}
	}
}

int main() {
	cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		cin>>nVertices>>nEdges;

		impossible = 0;
		for (int i = 0; i < nVertices; i++) {
			color[i] = 0;
			marked[i] = 0;
			adj[i].clear();
		}

		for (int i = 0; i < nEdges; i++) {
			int from, to; cin>>from>>to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		int guards = 0;
		for (int i = 0; i < nVertices; i++) {
			if (!marked[i]) {
				colorCount[0] = 0;
				colorCount[1] = 0;
				
				dfs(i);
				if (min(colorCount[0], colorCount[1]) == 0) {
					guards += 1;
				} else {
					guards += min(colorCount[0], colorCount[1]);
				}
			}
		}
		
		if (impossible) {
			cout<<"-1\n";
		} else {
			cout<<guards<<"\n";
		}
		
	}

    return 0;
}