#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> adj[100005];
int dist[100005];
int dist2[100005];


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m; cin>>n>>m;
	int p, g; cin>>p>>g;
	p--; g--;

	for (int i = 0; i < m; i++) {
		int u, v, w; cin>>u>>v>>w; u--; v--;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	for (int i = 0; i < n; i++) {
		dist[i] = 1e18;
		dist2[i] = 1e18;
	}

	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, g});
		dist[g] = 0;
	
		while (!q.empty()) {
			int cost = q.top().first;
			int u = q.top().second;
			q.pop();
	
			if (cost == dist[u]) {
				for (pair<int, int> edge: adj[u]) {
					int v = edge.second;
					int w = edge.first;
	
					if (cost+w<dist[v]) {
						dist[v] = cost+w;
						q.push({dist[v], v}); 
					}
				}
			}
		}
	}

	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, p});
		dist2[p] = 0;
	
		while (!q.empty()) {
			int cost = q.top().first;
			int u = q.top().second;
			q.pop();

			if (cost == dist2[u]) {
				for (pair<int, int> edge: adj[u]) {
					int v = edge.second;
					int w = edge.first;

					if (v == g) {
						continue;
					}
	
					if (cost+w<dist2[v]) {
						dist2[v] = cost+w;
						q.push({dist2[v], v}); 
					}
				}
			}
		}
	}

	vector<int> candidates;
	for (int i = 0; i < n; i++) {
		if (dist[i] == dist[p] && dist[i]+dist[p] < dist2[i]) {
			candidates.push_back(i+1);
		}
	}

	if (candidates.size() == 0) {
		cout<<"*"<<endl;
	} else {
		for (int i: candidates) {
			cout<<i<<" ";
		}
		cout<<endl;
	}

	return 0;
}