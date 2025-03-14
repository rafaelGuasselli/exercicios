#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1000005];
int consonant[1000005];
int dist[1000005][3];

int isVowel(char letter) {
	return (letter == 'Y' || letter == 'y' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u');
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin>>n;

	int index = 0;
	int last = -1;

	for (int i = 0; i < n; i++) {
		string pal; cin>>pal;

		last = index;
		for (int j = 0; j < pal.size(); j++) {
			consonant[index] = !isVowel(pal[j]); 
			adj[index].push_back(index+1);
			adj[index].push_back(last+pal.size());
			index++;
		}
	}
	
	for (int i = 0; i <= last; i++) {
		dist[i][0] = dist[i][1] = dist[i][2] = 1e9;
	}

	queue<pair<int, pair<int, int>>> q;
	q.push({1, {consonant[0], 0}});
	dist[0][consonant[0]] = 1; 

	while (!q.empty()) {
		int u = q.front().second.second;
		int countCon = q.front().second.first;
		int cost = q.front().first;
		q.pop();


		if (cost == dist[u][countCon]) {
			for (int v: adj[u]) {
				int w = 1e9;
				if (!consonant[v]) {
					w = 0;
				} else if (consonant[v] && countCon < 2) {
					w = countCon+1;
				} else {
					continue;
				}
	
				if (cost+1 < dist[v][w]) {
					dist[v][w] = cost+1;
					q.push({cost+1, {w, v}});
				}
			}
		}
	}

	int result = min({dist[last][0], dist[last][1], dist[last][2]});
	if (result == 1e9) {
		cout<<"*"<<endl;
	} else {
		cout<<result<<endl;
	}

	return 0;
}