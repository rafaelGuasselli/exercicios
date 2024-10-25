#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<long long, long long>
using namespace std;

int sign(ll val) {
	if (val==0) {
		return 0;
	} else if (val < 0) {
		return -1;
	} else {
		return 1;
	}
}

ll cross(pii a, pii b) {
	return a.second*b.first - a.first*b.second;
}

ll crossRelative(pii a, pii b, pii c) {
	return cross({b.first-a.first, b.second-a.second}, {c.first-a.first, c.second-a.second});
}

pii firstPoint;
bool lessThan(pii &a, pii &b){
	if (a == firstPoint) return 1;
	int side = sign(crossRelative(firstPoint, a, b));
	return side == 1;
}

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;

	vector<pii> pontos(n);
	for(int i = 0; i<n; i++){
		cin>>pontos[i].second>>pontos[i].first;
	}

	sort(pontos.begin(), pontos.end());
	firstPoint = pontos[0];
	sort(pontos.begin(), pontos.end(), lessThan);

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += pontos[i].second*pontos[(i+1)%n].first - pontos[(i+1)%n].second*pontos[i].first;
	}

	cout<<abs(sum)<<endl;
}