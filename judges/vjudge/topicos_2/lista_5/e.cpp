#include<bits/stdc++.h>

using namespace std;

int main() {
	int roadLength, nGasStations; cin>>roadLength>>nGasStations;
	vector<pair<int, int>> stations(nGasStations);
	for (int i = 0; i < nGasStations; i++) {
		int x, radius; cin>>x>>radius;
		stations[i].first = x - radius;
		stations[i].second = -(2 * radius);
	}

	sort(stations.begin(), stations.end());
	int remover = 0;
	return 0;
}