#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int fastPow(int n, int e, int m) {
	if (e <= 0) {
		return 1;
	} else if (e&1) {
		return (fastPow(n, e-1, m) * n) % m;
	} else {
		int result = fastPow(n, e/2, m);
		return (result * result) % m;
	}
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while (t--) {
		int n, e, m; cin>>n>>e>>m;
		cout<<fastPow(n, e, m)<<endl;
	}
}