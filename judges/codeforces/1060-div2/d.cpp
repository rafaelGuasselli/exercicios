#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> adj[200005];
vector<int> correctPath;
set<int> pathMembers;
int visited[200005];
int level[200005];


int dfs(int u, int t, int d) {
	visited[u] = 1;
	level[u] = d;
	int result = u == t;

	for (int v: adj[u]) {
		if (visited[v]) continue;
		result = max(dfs(v, t, d+1), result);
	}

	if (result) {
		pathMembers.insert(u);
		if (u != t) correctPath.push_back(u);
	}

	return result;
}

signed 	main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;

		pathMembers.clear();
		correctPath.clear();
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			visited[i] = 0;
			level[i] = 0;
		}

		for (int i = 0; i < n-1; i++) {
			int u, v; cin>>u>>v;
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}


		dfs(0, n-1, 0);
		reverse(all(correctPath));


		priority_queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			if (pathMembers.count(i)) {
				continue;
			}
			
			q.push({level[i], i});
		}


		vector<pair<int, int>> commands;
		
		int i = 0;
		while(!q.empty()){
			if ((i%2)!=(q.top().first%2) && !q.empty()) {
				auto [l, r] = q.top(); q.pop();
				commands.push_back({2, r});
			} 

			commands.push_back({1, -1});
			i++;
		}

		if (i%2==0) {
			commands.push_back({1, -1});
		}

		for (int i: correctPath) {
			commands.push_back({2, i});
			commands.push_back({1, -1});
		}
		
		
		cout<<commands.size()<<endl;
		for (auto [a, b]: commands) {
			if (a == 1) {
				cout<<1<<endl;
			} else {
				cout<<a<<" "<<b+1<<endl;
			}
		}
		cout<<endl;
	}
}