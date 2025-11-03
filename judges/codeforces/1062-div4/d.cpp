#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}

	return gcd(b%a, a);
}

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	vi primes;
	bitset<1000> isPrime;
	isPrime.set();
	for (int i = 2; i < 1000; i++) {
		if (isPrime.test(i)) {
			primes.push_back(i);
			for (int j = i*i; j < 1000; j+=i) {
				isPrime.reset(j);
			}
		}
	}


	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi a(n); 

		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}

		for (int p: primes) {
			int passa = 0;
			for (int v: a) {
				if (gcd(v, p) == 1) {
					passa = 1;
					break;
				}
			}

			if (passa) {
				cout<<p<<endl;
				break;
			}
		}

	}
}