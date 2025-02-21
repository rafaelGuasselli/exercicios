#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

vector<pair<int, int>> adj[100005];
int distancia[100005][101];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k; cin>>n>>m>>k;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin>>u>>v>>w;
		u--; v--;
		adj[u].push_back({w, v});
	}

	priority_queue<
		pair<pair<int, int>, int>, 
		vector<pair<pair<int, int>, int>>, 
		greater<pair<pair<int, int>, int>>
	> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			distancia[i][j] = 1e9;
		}
	}

	distancia[0][0] = 0;
	q.push({{0, 0}, 0});

	while (!q.empty()) {
		int cost = q.top().first.second;
		int dist = q.top().first.first;
		int u = q.top().second; q.pop();

		for (pair<int, int> edge: adj[u]) {
			int v = edge.second;
			int w = edge.first;

			if (cost+w <= k && dist+1 < distancia[v][cost+w]) {
				distancia[v][cost+w] = dist+1;
				q.push({{dist+1, cost+w}, v});
			}
		}
	}

	int minDist = 1e9;
	for (int i = 0; i <= k; i++) {
		minDist = min(minDist, distancia[n-1][i]);
	}

	if (minDist == 1e9) {
		cout<<-1<<endl;
	} else {
		cout<<minDist<<endl;
	}


	return 0;
}