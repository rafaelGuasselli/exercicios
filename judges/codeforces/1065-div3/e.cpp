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


vector<int> primes;
bitset<200005> isPrime;

int used[200005];
vector<int> primeiro;

int n; 
int ind = 0;

int next() {
	while (ind < primeiro.size() && (primeiro[ind] > n || used[primeiro[ind]])) {
		ind++;
	}

	if (ind < primeiro.size()) {
		used[primeiro[ind]] = 1;
		return primeiro[ind];
	} 

	return -1;
}

signed main() {
	cout.tie(0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	isPrime.set();
	for (int i = 2; i < 200005; i++) {
		if (isPrime.test(i)) {
			primes.push_back(i);
			for (int j = i; j < 200005; j += i) {
				isPrime.reset(j);
				primeiro.push_back(j);
			}
		}
	}


	int t; cin>>t;
	while(t--) {
		cin>>n;
		vector<int> result(n, -1);

		for (int i = 0; i <= n; i++) {
			used[i] = 0;
		}
		 
		ind = 0;
		for (int i = 1; i < n; i+= 3) {
			result[i] = next();
			if (i+1 < n) {
				result[i+1] = next();
			}	
		}

		int num=1;
		for (int i = 0; i < n; i++) {
			if (result[i] !=-1) continue;
			while (used[num]) {
				num++;
			}

			result[i] = num;
			used[num] = 1; 
		}
		

		for (int i = 0; i < n; i++) {
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
}

//a p p b p p c p p