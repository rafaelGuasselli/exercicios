#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
#define int long long
using namespace std;


vector<int> casas[200005];
vector<int> ruas;

int calcDistance(int x, int r) {
	int total = 0;
	for (int c: casas[r]) {
		total += abs(c-x);
	}
	return total;
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n; cin>>n;
	int smallest = 1e9;
	int biggest = 0;
	for (int i = 0; i < n; i++) {
		int r, c; cin>>r>>c;
		biggest = max(biggest, c);
		smallest = min(smallest, c);
		casas[r].push_back(c);
		if (casas[r].size() == 1) {
			ruas.push_back(r);
		}
	}

	int distancia = 0;
	for (int rua: ruas) {
		int left = smallest-1;
		int right = biggest+1;

		int smallestDist = 1e18;
		while (left <= right) {
			int middle1 = left + (right-left)/3;
			int middle2 = right - (right-left)/3;

			int dist1 = calcDistance(middle1, rua);
			int dist2 = calcDistance(middle2, rua);

			smallestDist = min(smallestDist, dist1);
			smallestDist = min(smallestDist, dist2);

			if (dist1 == dist2) {
				left = middle1+1;
				right = middle2-1;
			} else if (dist1 < dist2) {
				right = middle2-1;
			} else {
				left = middle1+1;
			}

		}	

		distancia += smallestDist;
	}

	cout<<distancia<<endl;
	return 0;
}