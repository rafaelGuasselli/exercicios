#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dist2(pair<int,int> a, pair<int, int> b){
    return (ll)pow((ll)a.first-b.first, 2)+(ll)pow((ll)a.second-b.second, 2);
}

ll choose(int n, int k){
    if (k == 0) return 1;
    return n * choose(n-1, k-1)/k;
}


int main() {
    while (1) {
        int n; cin>>n;

        if (n == 0) {
            break;
        }

        vector<pair<int, int>> points;
        ll total = 0;
        

        for (int i = 0; i < n; i++) {
            int x, y; cin>>x>>y;
            points.push_back({x, y});
        }

        for (int i = 0; i < points.size(); i++) {
            vector<ll> lines;
			pair<int, int> from = points[i];

            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                pair<int, int> to = points[j];
                ll distance = dist2(from, to);
                lines.push_back(distance);
            }

			sort(lines.begin(), lines.end());
			if (lines.size() > 1) {
				ll last = lines[0];
				int count = 0;
				for (ll distance: lines) {
					if (last == distance) {
						count++;
						total += choose(count, 2) - choose(count-1, 2);
					} else {
						count = 1;
					}

					last = distance;
				}
			}
        }

        cout<<total<<endl;
    }

    return 0;
}