#include<bits/stdc++.h>
using namespace std;

int nMovies, nActors;

vector<int> adjMOV[105];
vector<int> adjACT[1000005];
int visitedMOV[105];
int visitedACT[1000005];

map<pair<int, int>, pair<int, string>> memo;
string sufix; 

int target;
int nextValue[1001005];

int dfsMov(int m);
int dfsAct(int u) {
	int total = 101;
	if (target == u) {
		nextValue[u+101] = -1;
		return 1;
	}

	if (memo.find({u, target}) != memo.end()) {
		nextValue[u+101] = -1;
		sufix = memo[{u, target}].second;
		return memo[{u, target}].first;
	}

	visitedACT[u] = 1;
	for (int m:adjACT[u]) {
		if (!visitedMOV[m]) {
			int res = dfsMov(m);
			if (res < total) {
				total = res;
				nextValue[u+101] = m;
			}
		}
	}

	return total;
}

int dfsMov(int m) {
	int total = 101;
	visitedMOV[m] = 1;
	for (int a:adjMOV[m]) {
		if (visitedACT[a]) continue;

		int res = dfsAct(a);
		if (res < total) {
			total = res;
			nextValue[m] = a+101;
		}
	}

	return total+1;
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);


	memo.clear();
	cin>>nMovies>>nActors;
	for (int i = 0; i < nMovies; i++) {
		int n; cin>>n;
		for (int j = 0; j < n; j++) {
			int actor; cin>>actor; actor--;
			adjMOV[i].push_back(actor);
			adjACT[actor].push_back(i);
		}
	}

	int queries; cin>>queries;
	for (int i = 0; i < queries; i++) {
		int u, v; cin>>u>>v;
		u--; v--;

		if (u == v) {
			cout<<1<<endl;
			cout<<u+1<<endl;
			continue;
		}

		sufix = "";
		memset(visitedMOV, 0, sizeof(int) * nMovies);
		memset(visitedACT, 0, sizeof(int) * nActors);
		target = v;
		int result = dfsAct(u);


		if (result == 101) {
			cout<<-1<<endl;
		} else {
			string s;
			int tempU = u+101;
			int count = 0;
			while (tempU != -1) {
				if (count%2) {
					s += to_string(tempU+1) + " ";
				} else {
					s += to_string(tempU-100) + " ";
				}

				tempU = nextValue[tempU];
				count++;
			}
			
			cout<<result<<endl;
			cout<<s+sufix<<endl;
			memo[{min(u, v), max(u, v)}] = {result, s.substr(2, s.size()-2)};
		}
	}

	return 0;
}