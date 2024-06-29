#include<bits/stdc++.h>
#define pdi pair<double, int>
#define pii pair<int, int>


using namespace std;

int nVertices;
vector<pii> coordinates;
vector<vector<pdi>> adj;
vector<double> minLongJumpTo;

double pointsDistance(pair<int, int> a, pair<int, int> b){
	return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int main() {
	int scene = 1;
	while (true) {
		cin>>nVertices;

		if (nVertices == 0) {
			break;
		}

		adj.clear();
		coordinates.clear();
		minLongJumpTo.clear();

		adj.assign(nVertices, {});
		minLongJumpTo.assign(nVertices, 100000000);

		for (int i = 0; i < nVertices; i++) {
			int x, y; cin>>x>>y;

			for (int j = 0; j < coordinates.size(); j++) {
				pii coordinate = coordinates[j];
				double distance = pointsDistance({x, y}, coordinate);
				adj[i].push_back({distance, j});
				adj[j].push_back({distance, i});
			}
			
			coordinates.push_back({x, y});
		}
	
		priority_queue<pdi, vector<pdi>, greater<pdi>> q;

		q.push({0,0});
		minLongJumpTo[0] = 0;

		while (!q.empty()) {
			pdi current = q.top(); q.pop();
			double longJump = current.first;
			int u = current.second;

			if (longJump == minLongJumpTo[u]) {
				for (pdi edge: adj[u]) {
					double minLongJump = max(longJump, edge.first);
					
					if (minLongJump < minLongJumpTo[edge.second]) {
						minLongJumpTo[edge.second] = minLongJump;
						q.push({minLongJumpTo[edge.second], edge.second});
					}
				}
			}
		} 

		cout<<"Scenario #"<<scene++<<endl;
		cout<<"Frog Distance = "<<fixed<<setprecision(3)<<minLongJumpTo[1]<<endl<<endl;
	}

	return 0;
}