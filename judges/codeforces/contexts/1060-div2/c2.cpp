#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bitset<200005> primes;
vector<int> factor[200005];


signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	primes.set();
	for(int i = 2; i < 200005; i++) {
		if (primes.test(i)) {
			for (int j = i; j < 200005; j+=i) {
				primes.reset(j);
				factor[j].push_back(i);
			}
		}
	}	
	
	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		vector<pair<int, int>> c(n);

		for(int& v:a) cin>>v;
		for(int& v:b) cin>>v;
		for (int i = 0; i < n; i++) {
			c[i] = {b[i], i};
		}

		int passou = 0;
		map<int, int> freq;
		for (int v: a) {
			for (int f: factor[v]) {
				freq[f] += 1;
				if (freq[f] > 1) {
					passou = 1;
					break;
				}
			}

			if (passou) {
				break;
			}
		}

		if (passou) {
			cout<<0<<endl;
			continue;
		}



		sort(all(c));
		int cost = c[0].first+c[1].first;
		
		for (int i = 0; i < n; i++) {
			int v = a[i];
			
			for (int f: factor[v+1]) {
				if (freq.find(f) != freq.end()) {
					cost = min(cost, b[i]);
				}
			}
		}

		//b0<=b1<=b2...
		//cost = b0+b1
		//2*bx < b0+b1
		for (auto [t, i]: c) {
			if (2 * t >= cost) {
				break;
			}

			int v = a[i];
			for (auto [prime, qtd]: freq) {
				if (v % prime == 0) {
					continue;
				}

				int reqChange = prime - (v%prime);
				cost = min(cost, reqChange*b[i]);
			}
		}


		cout<<cost<<endl;
	}
}