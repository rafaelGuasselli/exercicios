#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main() {
	int nTests; cin>>nTests;

	for (int t = 0; t < nTests; t++) {
		int n, k; cin>>n>>k;

		if (n == 1) {
			cout<<0<<endl;
		} else {
			k--; n--;
			cout<<ceil((double)n/k)<<endl;
		}
	}

    return 0;
}