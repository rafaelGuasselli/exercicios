#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int nTests, nVertices, nEdges;
vector<vector<pii>> adj;
vector<int> distTo;

int main() {
	cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		cin>>nVertices>>nEdges;

		adj.clear();
		distTo.clear();

		adj.assign(nVertices, {});
		distTo.assign(nVertices, 100000000);

		for (int i = 0; i < nEdges; i++) {
			int u, v, time; cin>>u>>v>>time;

			adj[u].push_back({time, v});
		}

		distTo[0] = 0;
		int cicle = 0;
		for (int i = 0; i < nVertices; i++) {
			for (pii edge: adj[i]) {
				if (distTo[i] + edge.first < distTo[edge.second]) {
					distTo[edge.second] = distTo[i] + edge.first;

					if (i == nVertices-1) {
						cicle = 1;
					}
				}
			}
		}

		if (cicle) {
			cout<<"possible"<<endl;
		} else {
			cout<<"not possible"<<endl;
		}
	}

	return 0;
}