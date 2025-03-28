#include<bits/stdc++.h>
#define max(a, b) (a > b ? a : b) 
#define min(a, b) (a > b ? b : a)
//#define int long long
using namespace std;

int qtd[200005];

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin>>n;
	int biggest = 0;

	map<int, int> values;
	for (int i = 0; i < n; i++) {
		int val; cin>>val;
		values[val]++;
		biggest = max(biggest, val);
	}

	int maximo = 0;
	for (pair<int, int> num: values) {
		qtd[num.first] += num.second;
		int i = num.first;

		for (int j = 2*i; j <= biggest; j+=i) {
			if (qtd[i] >= qtd[j]) {
				qtd[j] = qtd[i];
			} 
		}

		maximo = max(qtd[i], maximo);
	}

	cout<<maximo<<endl;
	return 0;
}