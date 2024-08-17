#include<bits/stdc++.h>
using namespace std;

pair<double,double> batteries[1001];
int main() {
	int nBatteries; double dist; cin>>nBatteries>>dist;
	for (int i = 0; i < nBatteries; i++) {
		cin>>batteries[i].first;
		cin>>batteries[i].second;
	}
	
	batteries[nBatteries].first = dist;
	batteries[nBatteries].second = 0;

	double energy = batteries[0].second;
	double position = 0;
	double seconds = 0;


	for (int i = 0; i < nBatteries; i++) {
		double currentDistance = batteries[i+1].first - position;
		double speed = energy/currentDistance;
		double time = currentDistance/speed;

		cout<<energy<<" "<<currentDistance<<" "<<speed<<" "<<time<<endl;
		seconds += time;
		energy = batteries[i].second;
		position = batteries[i+1].first;
	}

	cout<<seconds<<endl;
	return 0;
}