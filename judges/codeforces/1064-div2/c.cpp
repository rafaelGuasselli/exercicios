#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef DEBUG
#define dcout cerr
#else
struct NullBuffer : std::streambuf {
	int overflow(int c) override { return c; }
} null_buffer;
ostream dcout(&null_buffer);
#endif

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while (t--) {
		int n, m; cin>>n>>m;

		multiset<int> a;
		vector<int> b(m);
		vector<int> c(m);

		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			a.insert(val);
		}

		for (int i = 0; i < m; i++) {
			cin>>b[i];
		}

		for (int i = 0; i < m; i++) {
			cin>>c[i];
		}

		vector<pair<int, int>> regain;
		vector<int> normal;
		
		for (int i = 0; i < m; i++) {
			if (c[i] > 0) {
				regain.push_back({b[i], c[i]});
			} else {
				normal.push_back(b[i]);
			}
		}

		sort(all(regain));
		int count = 0; 
		for (auto [most, rep]: regain) {
			auto val = a.lower_bound(most);
			if (val != a.end()) {
				a.erase(val);
				a.insert(max(*val, rep));
				count++;
			}
		}	

		sort(all(normal));
		for (int i: normal) {
			auto val = a.lower_bound(i);
			if (val != a.end()) {
				count++;
				a.erase(val);
			} else {
				break;
			}
		}

		cout<<count<<endl;
	}
}