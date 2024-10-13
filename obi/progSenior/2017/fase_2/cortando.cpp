#include<bits/stdc++.h>

using namespace std;

int n; 
int towers[100000];
vector<pair<int, int>> peaksAndValleys;
int isPeak(int i) {
	int left = 0;
	int right = 0;

	if (i == 0) {
		left = 1;
	} else {
		left = towers[i] > towers[i-1];
	}

	if (i+1 == n) {
		right = 1;
	} else {
		right = towers[i] > towers[i+1];
	}

	return right && left;
}

int isValley(int i) {
	int left = 0;
	int right = 0;

	left = towers[i] < towers[i-1];
	right = towers[i] < towers[i+1];
	return right & left;
}

int main() {
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>towers[i];
	}

	for (int i = 0; i < n; i++) {
		if (isPeak(i)) {
			peaksAndValleys.push_back({towers[i], -1});
		} else if (isValley(i)) {
			peaksAndValleys.push_back({towers[i], 1});
		}
	}

	sort(peaksAndValleys.begin(), peaksAndValleys.end());
	int total = 2;
	int totalCuts = 2;
	for (pair<int, int> tower: peaksAndValleys) {
		total += tower.second;
		totalCuts = max(totalCuts, total);
	}

	cout<<totalCuts<<endl;
	return 0;
}