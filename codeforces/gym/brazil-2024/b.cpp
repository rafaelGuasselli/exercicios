#include<bits/stdc++.h>
using namespace std;

int nMovies, nActors;

pair<int, int> parent[105];
vector<pair<int, int>> adj[105];
vector<int> actorFromMovie[105];
vector<int> moviesFromActor[1000005];

bitset<1000005> actorInMovie[105];
bitset<105> visited;


pair<int, int> bfs(int actorU, int actorV) {
	queue<int> q;
	visited.reset();

	for (int i = 0; i < nMovies; i++) {
		parent[i] = {i, -1};
	}

	for (int i: moviesFromActor[actorU]) {
		parent[i] = {i, actorU};
		visited.set(i);
		q.push(i);
	}

	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (actorInMovie[u].test(actorV)) {
			return {u, actorV};
		}

		for (pair<int, int> edge: adj[u]) {
			if (!visited.test(edge.first)) {
				visited.set(edge.first);
				parent[edge.first] = {u, edge.second};
				q.push(edge.first);
			}
		}
	}

	return {-1, -1};
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>nMovies>>nActors;
	for (int i = 0; i < nMovies; i++) {
		int n; cin>>n;
		for (int j = 0; j < n; j++) {
			int actor; cin>>actor; actor--;
			actorInMovie[i].set(actor);
			moviesFromActor[actor].push_back(i);
			actorFromMovie[i].push_back(actor);
		}
	}

	for (int i = 0; i < nMovies; i++) {
		int save[105]; 
		memset(save, 0, sizeof(int) * 105);
		
		for (int j: actorFromMovie[i]) {
			for (int v: moviesFromActor[j]) {
				adj[i].push_back({v, j});
				save[v] = j+1;
			} 
		}

		for (int v = 0; v < 105; v++) {
			if (save[v] != 0) {
				adj[i].push_back({v, save[v]-1});
			}
		}
	}

	int nQueries; cin>>nQueries;
	for (int i = 0; i < nQueries; i++) {
		int u, v; cin>>u>>v; u--; v--;
		pair<int, int> dest = bfs(u, v);
		if (dest.first == -1) {
			cout<<-1<<endl;
			continue;
		}

		vector<pair<int, int>> printar;
		while (1) {
			printar.push_back(dest);
			if (dest.second == u) {
				break;
			}

			dest = parent[dest.first];
		}

		reverse(printar.begin(), printar.end());
		cout<<printar.size()<<endl;

		for (int i = 0; i < printar.size(); i++) {
			if (i == 0) {
				cout<<printar[i].second+1<<" ";
			} else {
				cout<<printar[i].first+1<<" "<<printar[i].second+1<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}