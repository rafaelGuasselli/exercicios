#include<bits/stdc++.h>
#define ll long long

using namespace std;

int nVertices, nEdges, nHits; 

int dist[100005];
int passadas[100005];
vector<int> adj[100005];
vector<vector<int>> minPaths;
bitset<200005> disabledPaths;
bitset<100005> disabledVertices;
vector<int> hasPath[100005];

int diks(){
    for (int i = 0; i < nVertices; i++) {
        dist[i] = 1e9;
		passadas[i] = 0;
    }

    queue<pair<int, pair<int, vector<int>>>> q;
   
    q.push({0, {0, {0}}});
	dist[0] = 0;
    int chegou = 0;
    while (!q.empty()) {
		vector<int> path = q.front().second.second;
        int u = q.front().second.first;
        int cost = q.front().first; q.pop();
        
        if (u == nVertices-1) {
			cout<<"a"<<endl;
			minPaths.push_back(path);
			for (int w: path) {
				cout<<"-"<<w;
				passadas[w]++;
				hasPath[w].push_back(chegou);
			}
			cout<<endl;

			chegou++;
			continue;
		}

        if (dist[u] == cost) {
            for (int v: adj[u]) {
				if (cost+1 < dist[v]) {
					minPaths.clear();
				}

                if (cost+1 <= dist[v]) {
					dist[v] = cost+1;
					vector<int> newPath; newPath.insert(newPath.begin(), path.begin(), path.end());
					newPath.push_back(v);
                    q.push({cost+1, {v, newPath}});
                }
            }
        }
    }

	int criticos = 0;
	for (int i = 1; i < nVertices-1; i++) {
		if (passadas[i] == minPaths.size()) {
			criticos++;
		}
	}

	return criticos;
}

int main() {
    cin>>nVertices>>nEdges>>nHits;
    for (int i = 0; i < nEdges; i++) {
        int u, v; cin>>u>>v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < nVertices-1; i++) {
        dist[i] = 1e9;
    }

	disabledPaths.reset();
	int total = diks();
	int amountOfPaths = minPaths.size();
    
	cout<<total;
    for (int i = 0; i < nHits; i++) {
        int u; cin>>u; u--;
		disabledVertices.set(u);
        if (total == -1) {
            cout<<" "<<-1;
        } else {
			int remove = 0;

			for (int path: hasPath[u]) {
				if (!disabledPaths.test(path)) {
					amountOfPaths--;
					disabledPaths.set(path);
				}
			}

			int criticos = 0;
			for (int i = 1; i < nVertices-1; i++) {
				if (passadas[i] >= amountOfPaths && !disabledVertices.test(i)) {
					criticos++;
				}
			}

			if (amountOfPaths == 0) {
				total = -1;
				cout<<" "<<-1;
			} else {
				cout<<" "<<criticos;
			}		
        }
    }

    cout<<endl;

    return 0;
}