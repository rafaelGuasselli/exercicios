#include<bits/stdc++.h>
using namespace std;

set<int> adj[1000001];
set<int> parent[1000001];

vector<int> order;

int impossible;
int marked[1000001];
int nVertices, nEdges;
int from, to;

void dfs(int vertice) {
	if (marked[vertice]) {
		return;
	}

	if (parent[vertice].size() > 0) {
		return;
	}

	marked[vertice] = 1;
	order.push_back(vertice);

	for (int to: adj[vertice]) {
		parent[to].erase(vertice);
	}

	for (int to: adj[vertice]) {
		dfs(to);
	}
}

int main() {
	while (cin>>nVertices>>nEdges) {
		if (nVertices == 0 && nEdges == 0) {
			break;
		}

		order.clear();
		impossible = 0;

		for (int i = 1; i <= nVertices; i++) {
			marked[i] = 0;
			adj[i].clear();
			parent[i].clear();
		}

		for(int i = 0; i < nEdges; i++) {
			int from, to; cin>>from>>to;
			adj[from].insert(to);
			parent[to].insert(from);
		}

		for (int i = 1; i <= nVertices; i++) {
			dfs(i);
		}

		for (int i = 1; i <= nVertices; i++) {
			if (!marked[i]) {
				impossible = 1;
				break;
			}
		}

		if (impossible) {
			cout<<"IMPOSSIBLE"<<"\n";
		} else {
			for (int edge: order) {
				cout<<edge<<"\n";
			}
		}
	}

    return 0;
}