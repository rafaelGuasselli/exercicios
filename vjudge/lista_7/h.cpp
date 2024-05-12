#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int likes[100001];
int marked[100001];
int photos[100001];
int nVertices;

void dfs(int vertice, vector<int> path) {
	marked[vertice] = 1;

	auto it = lower_bound(path.begin(), path.end(), likes[vertice]);
	if (it == path.end()) {
		path.push_back(likes[vertice]);
	} else {
		*it = likes[vertice];
	}

	photos[vertice] = path.size();
	for (int child: adj[vertice]) {
		if (!marked[child]) {
			dfs(child, path);
		}
	}
}

int main() {
	cin>>nVertices;
	for (int i = 2; i <= nVertices; i++) {
		int vertice; cin>>vertice;
		
		adj[i].push_back(vertice);
		adj[vertice].push_back(i);
	}

	for (int i = 1; i <= nVertices; i++) {
		cin>>likes[i];
	}

	dfs(1, {});

	for (int i = 2; i <= nVertices; i++) {
		cout<<photos[i];
		if (i != nVertices) {
			cout<<" ";
		}
	}
	cout<<endl;

    return 0;
}