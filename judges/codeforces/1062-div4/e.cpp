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
 
struct middle {
	int size, left, direction;
	bool operator<(const middle a) const{
		return size<a.size;
	}
};
 
vi res;
vi amigos;
set<int> vis;
 
void tryInsert(int ind) {
	if (!vis.count(ind)) {
		vis.insert(ind);
		res.push_back(ind);
	}
}
 
signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
 
	int t; cin>>t;
	while (t--) {
		int n, k, x; cin>>n>>k>>x;
		res.clear();
		amigos.clear();
		vis.clear();
 
		amigos.assign(n, 0);
		for (int& a: amigos) { 
			cin>>a;
		}
 
		sort(all(amigos));
		priority_queue<middle> q;
		if (amigos[0] != 0) {
			int dist = amigos[0]+1;
			q.push({dist, 0, 1});
		}
 
		if (amigos[n-1] != x) {
			int dist = x-amigos[n-1]+1;
			q.push({dist, x, -1});
		}
 
		for (int i = 0; i < n-1; i++) {
			int left = amigos[i];
			int right = amigos[i+1];
			int middle = left+(right-left)/2;

			q.push({middle-left+1, middle, -1});
			q.push({right-middle, middle+1, 1});
		}
 
		while (!q.empty() && res.size() < k) {
			auto [ size, ind, dir ] = q.top(); q.pop();
			dcout<<size<<" "<<ind<<" "<<dir<<endl;
			if (dir == 1) {
				tryInsert(ind);
				q.push({size-1, ind+1, 1});
			} else {
				tryInsert(ind);
				q.push({size-1, ind-1, -1});
			}
		}
 
		for (int i = 0; i < k; i++) {
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}