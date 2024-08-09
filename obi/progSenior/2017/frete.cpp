	#include<bits/stdc++.h>

	using namespace std;

	int nVertices, nEdges;
	vector<pair<int, int>> adj[100];
	int distTo[100];


	int main() {
		cin>>nVertices>>nEdges;
		for (int i = 0; i < nEdges; i++) {
			int u, v, w; cin>>u>>v>>w; u--; v--;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}

		for (int i = 0; i < nVertices; i++) {
			distTo[i] = 1e9;
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		distTo[0] = 0;
		q.push({0,0});
		while (!q.empty()) {
			int u = q.top().second;
			int distance = q.top().first; q.pop();

			if (distTo[u] == distance) {
				for (pair<int, int> edge: adj[u]) {
					int weight = edge.first;
					int v = edge.second;
					if (distance + weight < distTo[v]) {
						distTo[v] = distance+weight;
						q.push({distTo[v], v});
					}
				}
			}
		}

		cout<<distTo[nVertices-1]<<endl;

		return 0;
	}