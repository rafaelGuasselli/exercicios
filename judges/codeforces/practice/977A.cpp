#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	int n, k; cin>>n>>k;
	for (int i = 0; i < k; i++) {
		if (n%10) {
			n--;
		} else {
			n /= 10;
		}
	}
	cout<<n<<endl;
	return 0;
}