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

#define int long long

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m; cin>>n>>m;
	vector<int> cities(n); for(int&v:cities)cin>>v;
	set<int> towers;
	for (int i = 0; i < m; i++) {
		int v; cin>>v;
		towers.insert(v);
	} 

	int minRadius = 0;
	for (int a:cities) {
		auto low = towers.lower_bound(a);
		int dist = 1e18;
		
		if (low != towers.end()) {
			int current = *low;
			dist = min(abs(current-a), dist);
		}

		if (low != towers.begin()) {
			int previous = *prev(low);
			dist = min(abs(a-previous), dist);
		}

		minRadius = max(minRadius, dist);
	}

	cout<<minRadius<<endl;
}	