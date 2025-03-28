#include<bits/stdc++.h>
#define int long long
using namespace std;

template<int size>
class BIT{
 public:
	int range[size+1];
	int read(int index) {
		index++;
		int runningSum = 0;
		while (index > 0) {
			runningSum += range[index];
			int rightMostSetBit = (index & (-index));
			index -= rightMostSetBit;
		}
 
		return runningSum;
	}
 
	void clear() {
		memset(range, 0, sizeof(int) * size);
	}

	void update(int index, int x) {
		index++;
		while (index < size) {
			range[index] += x;
			int rightMostSetBit = (index & (-index));
			index += rightMostSetBit;
		}
	}
 
	void updateRange(int l, int r, int x) {
		update(l, x);
		update(r+1, -x);
	}
};

vector<pair<int, int>> pares;
vector<pair<int, int>> compressao;
BIT<200005> bit; 

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		bit.clear();
		pares.clear();
		pares.resize(n);
		compressao.clear();
		compressao.resize(n);

		for (int i = 0; i < n; i++) {
			cin>>pares[i].first;
			cin>>compressao[i].first;
			compressao[i].second = i;
		} 
		
		sort(compressao.begin(), compressao.end());
		for (int i = 0; i < n; i++) {
			int index = compressao[i].second;
			pares[index].second = i+1;
		}

		sort(pares.begin(), pares.end());
		int total = 0;
		for (int i = n-1; i >= 0; i--) {
			total += bit.read(pares[i].second);
			bit.update(pares[i].second, 1);
		}

		cout<<total<<endl;
	}

	return 0;
}