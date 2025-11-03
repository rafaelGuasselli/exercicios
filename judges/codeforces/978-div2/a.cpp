#include<bits/stdc++.h>
using namespace std;

int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n, r; cin>>n>>r;

		int happy = 0;
		int sobrou = 0;
		for (int i = 0; i < n; i++) {
			int qtd; cin>>qtd;
			happy += qtd - qtd%2;
			r -= qtd/2;
			sobrou += qtd%2;
		}

		while (r * 2 > sobrou && sobrou > 0) {
			happy++;
			r--;
			sobrou--;
		}

		cout<<happy<<endl;
	}
	return 0;
}