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
#define int ll

int a[1000000];

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t; cin>>t;

	while (t--) {
		int n, m; cin>>n>>m;
		
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}

		multiset<int> smallests;
		int smallestSum = 0;
		for (int i = 0; i < m-1; i++) {
			smallests.insert(a[i]);
			smallestSum += a[i];
		}
		
		int biggestScore = m * a[m-1] - smallestSum;
		for (int i = m-1; i < n; i++) {
			int score = m*a[i] - smallestSum;
			biggestScore = max(biggestScore, score);

			if (smallests.size() == 0) {
				continue;
			}
			auto biggestSmallest = prev(smallests.end());
			if (a[i] < *biggestSmallest) {
				smallestSum += a[i];
				smallestSum -= *biggestSmallest;
				smallests.erase(biggestSmallest);
				smallests.insert(a[i]);
			}
		}

		cout<<biggestScore<<endl;
	} 
}