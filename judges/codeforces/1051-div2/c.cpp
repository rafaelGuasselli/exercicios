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
	while(t--) {
		int n; cin>>n;

		vector<int> permutation(n, 0);
		vector<int> dep(n, 0);
		vector<vector<int>> adj(n, vector<int>());
		vector<int> p(n, -1);


		for (int i = 0; i < n-1; i++) {
			int u, v, x, y; cin>>u>>v>>x>>y;
			u--; v--;

			if (x > y) {
				p[u] = v;
				dep[u]++;
				adj[v].push_back(u);
			} else {
				p[v] = u;
				dep[v]++;
				adj[u].push_back(v);
			}
		}


		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (dep[i] == 0) {
				q.push(i);
			}
		}

		int curr = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			permutation[u] = curr++;

			for (int v: adj[u]) {
				dep[v]--;
				if (dep[v] == 0) {
					q.push(v);
				}
			}
		}

		for (int i: permutation) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
}