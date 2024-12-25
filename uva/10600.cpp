#include<bits/stdc++.h>
//#define int long long
using namespace std;


int p[110];
vector<pair<int, int>> adj[110];
vector<pair<int, pair<int, int>>> edges;

int find(int u) {
	if (p[u] == u) {
		return u;
	}

	p[u] = find(p[u]);
	return p[u];
}

void join(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		return;
	} else {
		p[u] = v;
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int nSchools, nConnections; cin>>nSchools>>nConnections;

		edges.clear();
		for (int i = 0; i < nSchools; i++) {
			adj[i].clear();
			p[i] = i;
		}

		for (int i = 0; i < nConnections; i++) {
			int u, v, w; cin>>u>>v>>w;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
			edges.push_back({w, {u, v}});
		}

		sort(edges.begin(), edges.end());
		int total = 0;

		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			int w = edges[i].first;
			if (find(u) != find(v)) {
				total += w;
				join(u, v);
			}
		}

		for (int i = 0; i < nSchools; i++) {
			p[i] = i;
		}

		int total2 = 0;
		for (int i = 1; i < edges.size(); i++) {
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			int w = edges[i].first;
			if (find(u) != find(v)) {
				total2 += w;
				join(u, v);
			}
		}

		cout<<total<<" "<<total2<<endl;
	}

	return 0;
}