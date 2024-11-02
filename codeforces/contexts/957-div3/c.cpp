#include<bits/stdc++.h>
	
using namespace std;
	
int main() {
	int nTests; cin>>nTests;
	
	for (int t = 0; t < nTests; t++) {
		int n, m, k; cin>>n>>m>>k;
		int i = n;
		while (i >= k) {
			cout<<i<<" ";
			i--;
		}
	
		while (i > m) {
			cout<<i<<" ";
			i--;
		}
	
		for (int j = 1; j <= i; j++) {
			cout<<j<<" ";
		}
	
		cout<<endl;
	}
	
	return 0;
}