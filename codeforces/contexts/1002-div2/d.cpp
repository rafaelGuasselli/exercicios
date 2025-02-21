#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

vector<int> adj1[1001];
vector<int> adj2[1001];
<<<<<<< HEAD

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
=======
int dist[1001][1001];
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
<<<<<<< HEAD
	
	int t; cin>>t;
	while (t--) {
		int n, s1, s2; cin>>n>>s1>>s2;

		int m1; cin>>m1;
		for (int i = 0; i < m1; i++) {
			int u, v; cin>>u>>v; u--; v--;
=======

	int t; cin>>t;
	while (t--) {
		int n, s1, s2; cin>>n>>s1>>s2;
		s1--; s2--;
		
		for (int i = 0; i < n; i++) {
			adj1[i].clear();
			adj2[i].clear();
		}

		int m1; cin>>m1;
		for (int i = 0; i < m1; i++) {
			int u, v; cin>>u>>v; 
			u--; v--;

>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}

		int m2; cin>>m2;
		for (int i = 0; i < m2; i++) {
<<<<<<< HEAD
			int u, v; cin>>u>>v; u--; v--;
=======
			int u, v; cin>>u>>v; 
			u--; v--;

>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}

<<<<<<< HEAD
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
=======
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = 1e9;
			}
		}

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
		q.push({0, {s1, s2}});
		dist[s1][s2] = 0;
		
		while (!q.empty()) {
			int cost = q.top().first;
			pair<int, int> coord = q.top().second; q.pop();
			int u1 = coord.first;
			int u2 = coord.second;
			
			if (dist[u1][u2] == cost) {
				for (int v1: adj1[u1]) {
					for (int v2: adj2[u2]) {
						int weight = abs(v1 - v2);
						if (cost+weight < dist[v1][v2]) {
							dist[v1][v2] = cost+weight;
							q.push({dist[v1][v2], {v1, v2}});
						}
					}
				}
			}
		}

		int smallestCost = 1e9;
		for (int i = 0; i < n; i++) {
			bitset<1001> test; test.reset();
			int count = 0;

			for (int v: adj1[i]) test.set(v);
			for (int v: adj2[i]) count += test.test(v);

			if (count > 0) {
				smallestCost = min(smallestCost, dist[i][i]);
			}
		}

		if (smallestCost == 1e9) {
			cout<<-1<<endl;
		} else {
			cout<<smallestCost<<endl;
		}
>>>>>>> 2533e5089626c6abb7da64f0e31c47c29dcc9b6e
	}

	return 0;
}