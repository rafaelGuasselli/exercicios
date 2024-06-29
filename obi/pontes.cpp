#include<bits/stdc++.h>

using namespace std;

int nVertices, nEdges; 
vector<pair<int, int>> adj[1005];
int distTo[1005];

int main() {
	cin>>nVertices>>nEdges;
	nVertices += 1;

	for (int i = 0; i <= nEdges; i++) {
		int u, v, w; cin>>u>>v>>w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}

	for (int i = 0; i <= nVertices; i++) {
		distTo[i] = 10000000;
	}

	priority_queue<pair<int, int>> q;
	q.push({0, 0});
	distTo[0] = 0;

	while (!q.empty()) {
		pair<int, int> current = q.top(); q.pop();
		int weight = current.first;
		int vertice = current.second;

		if (weight == distTo[vertice]) {
			for (pair<int, int> child: adj[vertice]) {
				if (weight + child.first < distTo[child.second]) {
					distTo[child.second] = weight + child.first;
					q.push({distTo[child.second], child.second});
				}
			}
		}
	}

	cout<<distTo[nVertices]<<endl;
	return 0;	
}