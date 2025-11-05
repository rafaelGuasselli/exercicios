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
		int n, k, x; cin>>n>>k>>x;
		vi amigos(n, 0); for (int&i:amigos) cin>>i;
		priority_queue<vector<int>> middles;

		if (amigos[0] != 0) {
			int dist = amigos[0];
			middles.push({dist, 1, 1});
		}

		if (amigos[n-1] != x) {
			int dist = x-amigos[n-1];
			middles.push({dist, 1, 1});
		}

		for (int i = 0; i < n-1; i++) {
			int dist = amigos[i+1]-amigos[i];
			middles.push({dist, dist%2, 2});
		}

		while (k > 0) {
			int dist = middles.top()[0];
			int firstUse = middles.top()[1];
			int change = middles.top()[2];
			
			middles.pop();

			if (firstUse) {
				k--;
			} else {
				k-=change;
			}
		}
		cout<<middles.top()[0]<<endl;
	}
}