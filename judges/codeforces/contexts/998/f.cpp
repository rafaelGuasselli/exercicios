#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
#define int long long
using namespace std;

int modulo = 998244353;
int factorial[90000000];
int accumulatedFactorial[100005];

bitset<100005> prime;
vector<int> repetitions[100005];

void precompute() {
	prime.set(); 
	prime.reset(0);
	prime.reset(1);

	factorial[0] = 1;
	factorial[1] = 1;

	for (int i = 2; i < 90000000; i++) {
		factorial[i] = (factorial[i-1] * i) % modulo;
	}

	for (int p = 2; p <= 100002; p++) {
		if (prime.test(p))  {
			repetitions[p].push_back(1);

			for (int i = 2*p; i <= 100002; i += p) {
				int val = i;

				int rep = 0;
				while (val % p == 0) {
					val /= p;
					rep++;
				}

				repetitions[i].push_back(rep);
				prime.reset(i);
			}
		}
	}
}


int choose(int n, int k) {
	return factorial[n]/(factorial[k]*factorial[n-k]);
}

int chooseWithRep (int n, int k) {
	return choose(n+k-1, k);
}


signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	precompute();
	
	int t; cin>>t;
	while (t--) {
		int k, n; cin>>k>>n;
		
		
		cout<<n<<" ";
		for (int i = 2; i <= k; i++) {
			int total = 1;

			for (int x: repetitions[i]) {
				total = (total * choose(n+x, x+1)) % modulo;
			}

			cout<<total<<" ";
		}
		cout<<endl; 
	}

	return 0;
}