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

	int t;cin>>t;
	while (t--){
		int n; cin>>n;
		vi a(n); for(int&v:a) cin>>v;
		vi na;


		int prev = a[0];
		int count = 0;

		for (int i: a) {
			if (i!=prev) {
				na.push_back(count);
				count = 0;
			}

			count++;
			prev = i;
		}

		if (count > 0) {
			na.push_back(count);
		}

		sort(all(na));
		int biggest = 0;
		for (int i = 0; i < na.size(); i++) {
			biggest = max(biggest, (int)na[i] * ((int)na.size()-i));
		}

		cout<<biggest<<endl;

	}
}