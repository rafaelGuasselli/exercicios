#include<bits/stdc++.h>
using namespace std;

int nFrequencies, nApps, energyForChange, timeForChange;
int frequencies[5001][20];
int energyTo[5001][20];


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while (cin>>nFrequencies>>nApps>>energyForChange>>timeForChange) {
		if (nFrequencies == 0 && nApps == 0 && energyForChange == 0 && timeForChange == 0) {
			break;
		}

		for (int i = 1; i <= nApps; i++) {
			for (int j = 0; j < nFrequencies; j++) {
				int cost, time; cin>>cost>>time;
				frequencies[i][j] = cost * time;
			}
		}

		for (int i = 0; i <= nApps; i++) {
			for (int j = 0; j < nFrequencies; j++) {
				energyTo[i][j] = 1e9;
			}
		}

		energyForChange = energyForChange * timeForChange;
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
		energyTo[0][0] = 0;
		q.push({0, {0, 0}});

		while (!q.empty()) {
			int u = q.top().second.second;
			int f = q.top().second.first;
			int energy = q.top().first; q.pop();

			if (u == nApps) {
				continue;
			}

			if (energyTo[u][f] == energy) {
				int v = u+1;
				for (int j = 0; j < nFrequencies; j++) {
					int cost = 0;
					if (j != f) {
						cost = energyForChange;
					}

					cost += energy;
					cost += frequencies[v][j];
					if (cost < energyTo[v][j]) {
						energyTo[v][j] = cost;
						q.push({cost, {j, v}});
					}
				}
			}
		}

		int smallest = 1e9;
		for (int i = 0; i < nFrequencies; i++){
			smallest = min(energyTo[nApps][i], smallest);
		}

		cout<<smallest<<endl;		
	}

    return 0;
}