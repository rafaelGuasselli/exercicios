#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

vector<int> adj1[1001];
vector<int> adj2[1001];

int dist1[1001];
int dist2[1001];

bitset<1001> visited;
void bfs(int s, int* dist, vector<int>* adj) {
	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v: adj[u]) {
			if(visited.test(v)) continue;
			dist[v] = dist[u]+1;
			q.push(v);
		}
	}
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int t; cin>>t;
	while (t--) {
		int n, s1, s2; cin>>n>>s1>>s2;

		int m1; cin>>m1;
		for (int i = 0; i < m1; i++) {
			int u, v; cin>>u>>v; u--; v--;
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}

		int m2; cin>>m2;
		for (int i = 0; i < m2; i++) {
			int u, v; cin>>u>>v; u--; v--;
			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}

		bfs(s1, dist1, adj1);
		bfs(s2, dist2, adj2);


		int smallest = 1e9;
		for (int i = 0; i < n; i++) {
			if (dist1[i] % 2 == dist2[i] % 2) {
				vector<int> inter; 
				sort(adj1[i].begin(), adj1[i].end());
				sort(adj2[i].begin(), adj2[i].end());
				set_intersection(adj1[i].begin(), adj1[i].end(), adj2[i].begin(), adj2[i].end(), inter);
				if (inter.size() == 0) continue;
				
				
			}
		}
	}

	return 0;
}