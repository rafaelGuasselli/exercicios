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

int n, k; 
vector<int> vals;

int test(int median) {
	int requiredK = 0;

	auto low = lower_bound(all(vals), median);
	int indLow = low-vals.begin();

	for (int i = n/2; i < indLow; i++) {
		requiredK += max(0LL, median-vals[i]);
	}

	return requiredK;
}	



signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin>>n>>k;

	for (int i = 0; i < n; i++) {
		int v; cin>>v;
		vals.push_back(v);
	}

	sort(all(vals));
	int left = 0;
	int right = 1e10;
	int maxMedian = 0;
	while (left<=right) {
		int mid = left+(right-left)/2;
		int reqK = test(mid);

		if (reqK <= k) {
			maxMedian = max(maxMedian, mid);
			left = mid+1;
		} else {
			right = mid-1;
		}
	}

	cout<<maxMedian<<endl;
}