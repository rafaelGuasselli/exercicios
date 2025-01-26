#include<bits/stdc++.h>
	
using namespace std;
	
int main() {
	int nTests; cin>>nTests;
	for (int t = 0; t < nTests; t++) {
		int n; cin>>n;
		int maior = 0;
	
		int par = (n%2) ? n/2 + 1 : n/2;
		int impar = n/2;
	
		int mPar = 0;
		int mImpar = 0;
	
		for (int i = 0; i < n; i++) {
			int val; cin>>val;
			if (i%2 == 0) {
				mPar = max(mPar, val);
			} else {
				mImpar = max(mImpar, val);
			}
		}
	
		cout<<max((par+mPar), (impar+mImpar))<<endl;
	}
	
	return 0;
}