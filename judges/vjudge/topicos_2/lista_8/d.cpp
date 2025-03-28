#include<bits/stdc++.h>

using namespace std;


vector<pair<double, int>> adj[100];
int nVertices; 
int p[100];
int nChildren[100];

double distanceBetweenPoints(pair<double, double> a, pair<double, double> b){
	return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int find(int vertice) {
	if (vertice == p[vertice]) {
		return vertice;
	}

	p[vertice] = find(p[vertice]);
	return p[vertice];
}

void join(int u, int v) {
	u = find(u);
	v = find(v);
	if (nChildren[u] > nChildren[v]) {
		p[v] = u;
		nChildren[u] += nChildren[v];
	} else {
		p[u] = v;
		nChildren[v] += nChildren[u];
	}
}


int main() {
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		cin>>nVertices;
		vector<pair<double, double>> points;

		for (int i = 0; i < nVertices; i++) {
			adj[i].clear();
			p[i] = i;
			nChildren[i] = 1;	
		}

		vector<pair<double, pair<int, int>>> q;
		for (int i = 0; i < nVertices; i++) {
			double x, y; cin>>x>>y;
			int u = points.size();
			for (int v = 0; v < points.size(); v++) {
				double distance = distanceBetweenPoints({x, y}, points[v]);
				adj[u].push_back({distance, v});
				adj[v].push_back({distance, u});

				q.push_back({distance, {u, v}});
			}

			points.push_back({x, y});
		}


		sort(q.begin(), q.end(), greater<pair<double, pair<int, int>>>());

		double totalDistance = 0;
		while (!q.empty()){
			pair<double, pair<int, int>> current = q.back(); q.pop_back();
			int u = current.second.first;
			int v = current.second.second;
			double distance = current.first;

			if (find(u) != find(v)) {
				join(u, v);
				totalDistance += distance;
			}
		}

		if (t > 0) {
			cout<<"\n";
		}

		cout<<setprecision(2)<<fixed<<totalDistance<<endl;
	}
	

	return 0;
}