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
		vector<int> a(n);
		vector<int> p(n+1); 


		for (int i = 0; i < n; i++) {
			cin>>a[i];
			p[i] = -1;
		}

		int smallestOnMainTree = a[0];
		int biggestOutsider = 0;
		int smallestOutsider = 1e9;
		queue<int> q;

		for (int i = 1; i < n; i++) {
			if (biggestOutsider && a[i] > biggestOutsider && a[i] > smallestOnMainTree) {
				p[a[i]] = smallestOnMainTree;
				while (!q.empty()) {
					int k = q.front(); q.pop();
					p[k] = a[i];
				}	

				smallestOnMainTree = min(smallestOutsider, smallestOnMainTree);
				biggestOutsider = 0;
				smallestOutsider = 1e9;
			} else if (a[i] > smallestOnMainTree) {
				p[a[i]] = smallestOnMainTree;
			} else if (a[i] < smallestOnMainTree) {
				biggestOutsider = max(biggestOutsider, a[i]);
				smallestOutsider = min(smallestOutsider, a[i]);
				q.push(a[i]);
			}
		}


		if (biggestOutsider) {
			cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
			for (int i = 1; i <= n; i++) {
				if (p[i] != -1) {
					cout<<p[i]<<" "<<i<<endl;
				}
			}
		}
	}	
}