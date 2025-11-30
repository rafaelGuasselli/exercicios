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

vector<pair<int, int>> adj[100005];
int xorA[100005];
int xorB[100005];

void dfs(int u, int p, int x, int* xorX, int avoid) {
	xorX[u] = x;
	for (auto [w, v]: adj[u]) {
		if (v == p) continue;
		if (v == avoid) continue;
		dfs(v, u, x^w, xorX, avoid);
	}
}

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while (t--) {
		int n, a, b; cin>>n>>a>>b; a--; b--;
		for (int i = 0; i < n; i++) {
			adj[i].clear();
			xorB[i] = xorA[i] = -1;
		}

		for (int i = 0; i < n-1; i++) {
			int u, v, w; cin>>u>>v>>w;
			u--; v--;
			adj[u].push_back({w, v});
			adj[v].push_back({w, u});
		}

		dfs(a, -1, 0, xorA, b);
		dfs(b, -1, 0, xorB, -1);

		int  possible = xorB[a]==0;
		map<int, int> bMap;
		for (int i = 0; i < n; i++) {
			if(xorB[i] == -1) continue;
			if (i != b) {
				bMap[xorB[i]] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			if(xorA[i] == -1) continue;
			if(i == b) continue;
			if (bMap.count(xorA[i])) {
				possible = 1;
				break;
			}
		}

		if (possible) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
		}

	}
}