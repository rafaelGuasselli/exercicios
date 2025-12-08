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
	while (t--) {
		int n; cin>>n;
		
		map<int,  int> s;
		for (int i = 0; i < 2 * n; i++) {
			int val; cin>>val;
			s[val]++;
		}


		int qtdImp = 0;
		int qtdParOtimo = 0;
		int qtdParNaoOtimo = 0;
		
		for (auto[val, qtd]: s) {
			if (qtd%2) {
				qtdImp++;
			} else if ((qtd/2)%2 == 0) {
				qtdParNaoOtimo++;
			} else {
				qtdParOtimo++;
			}
		}
		
		int imp = qtdImp;
		imp += 2 * qtdParOtimo;
		imp += 4 * (qtdParNaoOtimo/2);
		qtdParNaoOtimo %= 2;
		if (qtdImp >= 2 && qtdParNaoOtimo) {
			imp += 2;
		}

		
		cout<<imp<<endl;
	}
}