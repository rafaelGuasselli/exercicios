#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k; cin>>n>>k;
	vector<int> lista(n);
	for (int &a: lista) cin>>a;

	vector<int> prefix(n, 1e18);
	vector<int> suffix(n, 1e18);

	for (int i = n-2; i >= 0; i--) {
		suffix[i] = min(suffix[i+1], lista[i+1]);
	}

	for (int i = 1; i < n; i++) {
		prefix[i] = min(prefix[i-1], lista[i-1]);
	}

	int maior = 0;
	set<int> range;
	for (int i = 0; i < n; i++) {
		int p = 1e18;
		if (i-k >= 0) {
			range.erase(lista[i-k]+i);
			p = prefix[i-k+1];
		}

		range.insert(lista[i]+k+i);
		int atual = min({p, suffix[i], (*range.begin()-i)});
		maior = max(maior, atual);
	}

	cout<<maior<<endl;
}