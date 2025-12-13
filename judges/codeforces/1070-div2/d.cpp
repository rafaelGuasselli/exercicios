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


int a[400005];
vector<pair<int, int>> edges;
map<int, int> dp[400005];

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while(t--) {
		int n, m; cin>>n>>m;

		edges.clear();
		for (int i = 0; i < n; i++) {
			cin>>a[i];
			dp[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int u, v; cin>>u>>v;
			u--; v--;
			edges.push_back({u, v});
		}

		sort(all(edges), [](auto& u, auto& v){
			return a[u.second] < a[v.second];
		});


		int total = m;
		for (auto [u, v]: edges) {
			int x = a[v]-a[u];

			int count = 0;
            if (x >= 1 && dp[u].count(x)) {
                count = dp[u][x];
            }
			
			total = (total+count)%998244353; //v = u+x
			if (dp[v].count(a[u])) {
				dp[v][a[u]] = (dp[v][a[u]]+count+1)%998244353;
			} else {
				dp[v][a[u]] = (count+1)%998244353;	
			}
		}

		cout<<total<<endl;
	}	
}