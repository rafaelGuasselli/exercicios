#include<bits/stdc++.h>
//#define int long long
using namespace std;

int matrix[200005];
int matrix2[200005];
int dist[200005];
pair<int, int> parent[200005];


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m; cin>>n>>m;
	int playerI, playerJ; 
	vector<pair<int, int>> ilhas;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char val; cin>>val;

			if (val == '#') {
				matrix[i*n+j] = 0;
				matrix2[i*n+j] = 0;
			} else if (val == '*'){
				matrix[i*n+j] = 0;
				matrix2[i*n+j] = 0;
				ilhas.push_back({i, j});
			} else if (val == 'T'){
				matrix[i*n+j] = 0;
				matrix2[i*n+j] = 0;
				playerI = i; playerJ = j;
			}

			if (val == '.') {
				matrix[i*n+j] = 1;
				matrix2[i*n+j] = 1;
			}

			dist[i*n+j] = 1e9;
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({0, {playerI, playerJ}});
	dist[playerI*n+playerJ] = 0;

	while (!q.empty()) {
		int i = q.top().second.first;
		int j = q.top().second.second;
		int cost = q.top().first; q.pop();

		if (dist[i*n+j] == cost) {
			vector<pair<int, int>> nexts = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
			for (pair<int, int> next: nexts) {
				if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
					continue;
				}

				if (dist[next.first*n+next.second] > matrix[next.first*n+next.second] + cost) {
					dist[next.first*n+next.second] = matrix[next.first*n+next.second] + cost;
					parent[next.first * n + next.second] = {i, j};
					q.push({dist[next.first*n+next.second], {next.first, next.second}});
				}
			}
		}
	}

	int total = dist[ilhas[0].first*n+ilhas[0].second];
	for (pair<int, int> p = {ilhas[0].first, ilhas[0].second}; 1; p = parent[p.first*n + p.second]) {
		matrix[p.first*n+p.second] = 0;
		if (p.first == playerI && p.second == playerJ) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i*n+j] = 1e9;
		}
	}

	q.push({0, {ilhas[0].first, ilhas[0].second}});
	dist[ilhas[0].first*n+ilhas[0].second] = 0;

	while (!q.empty()) {
		int i = q.top().second.first;
		int j = q.top().second.second;
		int cost = q.top().first; q.pop();

		if (dist[i*n+j] == cost) {
			vector<pair<int, int>> nexts = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
			for (pair<int, int> next: nexts) {
				if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
					continue;
				}

				if (dist[next.first*n+next.second] > matrix[next.first*n+next.second] + cost) {
					dist[next.first*n+next.second] = matrix[next.first*n+next.second] + cost;
					parent[next.first * n+  next.second] = {i, j};
					q.push({dist[next.first*n+next.second], {next.first, next.second}});
				}
			}
		}
	}

	for (pair<int, int> p = {ilhas[1].first, ilhas[1].second}; 1; p = parent[p.first *n + p.second]) {
		matrix[p.first*n+p.second] = 0;
		if (p.first == ilhas[0].first && p.second == ilhas[0].first) {
			break;
		}
	}


	total += dist[ilhas[1].first*n+ilhas[1].second];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i*n+j] = 1e9;
		}
	}


	q.push({0, {playerI, playerJ}});
	dist[playerI*n+playerJ] = 0;

	while (!q.empty()) {
		int i = q.top().second.first;
		int j = q.top().second.second;
		int cost = q.top().first; q.pop();

		if (dist[i*n+j] == cost) {
			vector<pair<int, int>> nexts = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
			for (pair<int, int> next: nexts) {
				if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
					continue;
				}

				if (dist[next.first*n+next.second] > matrix2[next.first*n+next.second] + cost) {
					dist[next.first*n+next.second] = matrix2[next.first*n+next.second] + cost;
					parent[next.first * n + next.second] = {i, j};
					q.push({dist[next.first*n+next.second], {next.first, next.second}});
				}
			}
		}
	}

	int total2 = dist[ilhas[1].first*n+ilhas[1].second];
	for (pair<int, int> p = {ilhas[1].first, ilhas[1].second}; 1; p = parent[p.first * n +  p.second]) {
		matrix2[p.first*n+p.second] = 0;
		if (p.first == playerI && p.second == playerJ) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i*n+j] = 1e9;
		}
	}

	q.push({0, {ilhas[1].first, ilhas[1].second}});
	dist[ilhas[1].first*n+ilhas[1].second] = 0;

	while (!q.empty()) {
		int i = q.top().second.first;
		int j = q.top().second.second;
		int cost = q.top().first; q.pop();

		if (dist[i*n+j] == cost) {
			vector<pair<int, int>> nexts = {{i+1, j}, {i, j+1}, {i-1, j}, {i, j-1}};
			for (pair<int, int> next: nexts) {
				if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m) {
					continue;
				}

				if (dist[next.first*n+next.second] > matrix2[next.first*n+next.second] + cost) {
					dist[next.first*n+next.second] = matrix2[next.first*n+next.second] + cost;
					parent[next.first * n +  next.second] = {i, j};
					q.push({dist[next.first*n+next.second], {next.first, next.second}});
				}
			}
		}
	}

	for (pair<int, int> p = {ilhas[0].first, ilhas[0].second}; 1; p = parent[p.first * n + p.second]) {
		matrix2[p.first*n+p.second] = 0;
		if (p.first == ilhas[1].first && p.second == ilhas[1].second) {
			break;
		}
	}

	total2 += dist[ilhas[0].first*n+ilhas[0].second];
	cout<<min(total, total2)<<endl;
	return 0;
}