#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> adj[602];
int res[602][602];
map<int, int> code;

void addCode(int i) {
	if (code.find(i) == code.end()) {
		code[i] = code.size()+201;
		adj[code[i]].push_back(code[i]+200);
		adj[code[i]+200].push_back(code[i]);

		res[code[i]][code[i]+200] = 1;

		adj[code[i]+200].push_back(601);
		res[code[i]+200][601] = 1;
	}
}

bitset<602> visited;
int parent[602];

int findPath() {
	visited.reset();
	memset(parent, 0, sizeof(int) * 602);

	queue<int> q;
	q.push(0);
	visited.set(0);
	parent[0] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();
		
		for (int v: adj[u]) {
			if (!visited.test(v) && res[u][v] > 0) {
				parent[v] = u;
				q.push(v);
				visited.set(v);
			}
		}
	}

	return visited.test(601);
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	
	for (int i = 0; i < 602; i++) {
		for (int j = 0; j < 602; j++) {
			res[i][j] = 0;
		}
	}

	int n, d; cin>>n>>d;
	for (int i = 1; i <= n; i++) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		res[0][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int x; cin>>x;
		if (x-d >= 0) {
			addCode(x-d);
			adj[i].push_back(code[x-d]);
			adj[code[x-d]].push_back(i);

			res[i][code[x-d]] = 1;
		} 

		if (d == 0) continue;
		addCode(x+d);
		adj[i].push_back(code[x+d]);
		adj[code[x+d]].push_back(i);
		res[i][code[x+d]] = 1;
	}

	int maxFlow = 0;
	while (findPath()) {
		int bottleNeck = 1e9;
		for (int v = 601; v != 0; v = parent[v]) {
			bottleNeck = min(bottleNeck, res[parent[v]][v]);
		}

		for (int v = 601; v != 0; v = parent[v]) {
			res[parent[v]][v] -= bottleNeck;
			res[v][parent[v]] += bottleNeck;
		}

		maxFlow += bottleNeck;
	}

	cout<<maxFlow<<endl;
	return 0;
}