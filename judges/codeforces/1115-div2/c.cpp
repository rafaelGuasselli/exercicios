#include <bits/stdc++.h>

using namespace std;

int minPiecesToBreakLevel(multiset<int, greater<int>>& ordem, int levelStrength, int m) {
	int count = 0;
	for (auto& val: ordem) {
		if (levelStrength <= 0 || count == m) {
			return count;
		}
		
		count++;
		levelStrength -= val;
	}

	return m;
}

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


int v[1000005];

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;
	while (t--) {
		int n, m; cin>>n>>m;
		for (int i = 0; i < n; i++) {
			cin>>v[i];
		}

		vector<vector<int>> mat = vector(n, vector<int>(m, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin>>mat[i][j];
			}
		}

		multiset<int, greater<int>> ordem;
		int minimo = m;
		for (int i = n-1; i>=0; i--) {
			for (int j = 0; j < m; j++) {
				ordem.insert(mat[i][j]);
			}

			int minPieces = minPiecesToBreakLevel(ordem, v[i], m);
			minimo = min(minimo, minPieces);
		}

		cout<<minimo<<endl;
	}
	
}