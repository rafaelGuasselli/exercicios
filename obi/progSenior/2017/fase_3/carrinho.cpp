#include<bits/stdc++.h>

using namespace std;

double timeTo[1005];
double pos[1005];
double battery[1005];

double timeToDrive(double battery, double distance){
	return (double)pow(distance, 2)/battery;
}

int main() {
	int n; double distance; cin>>n>>distance;
	for (int i = 0; i < n; i++) {
		cin>>pos[i];
		cin>>battery[i];
	}

	pos[n] = distance;
	battery[n] = 0;

	for (int i = 0; i <= n; i++) {
		timeTo[i] = 1e18;
	}

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	timeTo[0] = 0;
	q.push({0, 0});

	while (!q.empty()) {
		double cost = q.top().first;
		int index = q.top().second; q.pop();
		double position = pos[index];
		double charge = battery[index];

		for (int i = index+1; i <= n; i++) {
			if (cost + timeToDrive(charge, pos[i]-position) < timeTo[i]) {
				timeTo[i] = cost + timeToDrive(charge, pos[i]-position);
				q.push({timeTo[i], i});
			}
		}
	}

	cout<<fixed<<setprecision(3)<<timeTo[n]<<endl;
	return 0;
}