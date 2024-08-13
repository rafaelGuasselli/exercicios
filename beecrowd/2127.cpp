#include<bits/stdc++.h>

using namespace std;

int parent[1005];
int countV[1005];

int find(int u){
	if (parent[u] == u) {
		return u;
	}

	parent[u] = find(parent[u]);
	return parent[u];
}

int join(int u, int v){
	u = find(u); v = find(v);
	if (u == v)	return 0;
	if (countV[u] > countV[v]) {
		parent[v] = u;
		countV[u] += countV[v];
	} else {
		parent[u] = v;
		countV[v] += countV[u];
	}

	return 1;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int nVertices, nEdges;
	int instancia = 1;
	while (cin>>nVertices>>nEdges) {
		for (int i = 0; i < nVertices; i++) {
			parent[i] = i;
			countV[i] = 1;
		}


		vector<pair<int, pair<int, int>>>  cipos[3];
		for (int i = 0; i < nEdges; i++) {
			int u, v, w; cin>>u>>v>>w; u--; v--;

			if (w == 1235) {
				cipos[0].push_back({w, {u, v}});
			} else if (w == 8977) {
				cipos[1].push_back({w, {u, v}});
			} else {
				cipos[2].push_back({w, {u, v}});
			}
		}


		int total = 0;
		int countLigacoes = 0;

		for (int i = 0; i < 3; i++) {
			for (pair<int, pair<int, int>> edge:cipos[i]) {
				int u = edge.second.first;
				int v = edge.second.second;

				if (countLigacoes >= nVertices-1) {
					break;
				}

				int success = join(u, v);
				if (success) {
					total += edge.first;
					countLigacoes++;
				}
			}
		}


		cout<<"Instancia "<<instancia++<<endl;
		cout<<total<<endl<<endl;
	}

	return 0;
}