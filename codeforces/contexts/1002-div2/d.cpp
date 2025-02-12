#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

vector<int> adj1[1001];
vector<int> adj2[1001];
int dist[1001][1001];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

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

			adj1[u].push_back(v);
			adj1[v].push_back(u);
		}

		int m2; cin>>m2;
		for (int i = 0; i < m2; i++) {
			int u, v; cin>>u>>v; 
			u--; v--;

			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}

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
	}

	return 0;
}